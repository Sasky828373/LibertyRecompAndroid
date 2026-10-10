#!/bin/bash
# Frame rate of the game surface, measured by SurfaceFlinger.
#   fps.sh [seconds]   (default 10; SurfaceFlinger keeps only the last 128
#                       frames, so it is sampled once a second and merged)
set -euo pipefail
. "$(dirname "$0")/env.sh"
SECONDS_TOTAL="${1:-10}"
LAYER=$(adbs shell dumpsys SurfaceFlinger --list | tr -d '\r' | grep -E "^SurfaceView\[$PKG/.*\(BLAST\)" | head -1)
[ -n "$LAYER" ] || { echo "game surface not found - is the game in the foreground?"; exit 1; }
OUT="$(mktemp)"
adbs shell "dumpsys SurfaceFlinger --latency-clear '$LAYER'" >/dev/null
for _ in $(seq "$SECONDS_TOTAL"); do
  sleep 1
  adbs shell "dumpsys SurfaceFlinger --latency '$LAYER'" | tr -d '\r' >> "$OUT"
done
python - "$(winpath "$OUT")" <<'EOF'
import math
import sys
present = set()
for line in open(sys.argv[1], encoding="utf-8"):
    parts = line.split()
    if len(parts) != 3:
        continue
    try:
        t = int(parts[1])
    except ValueError:
        continue
    if 0 < t < 2**62:
        present.add(t)
times = sorted(present)
if len(times) < 3:
    sys.exit("not enough frames")
span = (times[-1] - times[0]) / 1e9
durations = sorted((b - a) / 1e6 for a, b in zip(times, times[1:]))
def percentile(p):
    index = (len(durations) - 1) * p
    lo = int(index)
    hi = min(lo + 1, len(durations) - 1)
    return durations[lo] + (durations[hi] - durations[lo]) * (index - lo)
fps = (len(times) - 1) / span
print(f"fps {fps:.1f} over {span:.1f}s; presentation interval ms:"
      f" p50 {percentile(.50):.2f} p95 {percentile(.95):.2f}"
      f" p99 {percentile(.99):.2f} max {durations[-1]:.2f}")
for hz in (120, 60):
    target = 1000 / hz
    long = sum(d > target * 1.5 for d in durations)
    print(f"  {hz}Hz target {target:.3f}ms: {long}/{len(durations)}"
          f" intervals > {target*1.5:.2f}ms")
# Display refresh cannot safely be inferred from game timestamps when frames
# are missed. Show both distributions instead of assuming 60 Hz on 120 Hz phones.
for hz in (120, 60):
    period = 1000 / hz
    vs = [max(1, round(d / period)) for d in durations]
    hist = {k: vs.count(k) for k in sorted(set(vs))}
    print(f"intervals in nominal {hz}Hz refreshes:",
          "  ".join(f"{k}x={v}" for k, v in hist.items()))
EOF
rm -f "$OUT"

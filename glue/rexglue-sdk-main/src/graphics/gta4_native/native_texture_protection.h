#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

namespace rex::graphics::gta4_native {

// Include implicit host-pass inputs as well as title sampler bindings. A queued
// composite owns its half-scene generation even when the title never binds it.
template <typename Command, typename Visitor>
void VisitNativeCommandTextureGenerations(const Command& command, Visitor&& visit) {
  const auto texture = [&](const auto& resource) {
    if (!resource) return;
    visit(resource->generation);
    if (resource->packed_depth_source) visit(resource->packed_depth_source->generation);
  };
  texture(command.resolve_destination);
  texture(command.depth_handoff_source);
  texture(command.present_source);
  texture(command.postfx_half_scene);
  for (const auto& resource : command.textures) texture(resource);
}

// Queue lock owns this index. Counts are logical references, not shared_ptrs or
// GPU ownership. Every zero count is removed immediately. If an invariant is
// violated the renderer falls back to its original queue scan, never guessing
// that an image is safe to retire.
class NativeTextureProtectionIndex {
 public:
  bool Retain(uint64_t generation) {
    if (!generation) return true;
    auto& count = counts_[generation];
    if (count == UINT64_MAX) { valid_ = false; return false; }
    ++count; return true;
  }
  bool Release(uint64_t generation) {
    if (!generation) return true;
    const auto it = counts_.find(generation);
    if (it == counts_.end() || !it->second) { valid_ = false; return false; }
    if (!--it->second) counts_.erase(it);
    return true;
  }
  void AppendTo(std::unordered_set<uint64_t>& destination) const {
    destination.reserve(destination.size() + counts_.size());
    for (const auto& [generation, count] : counts_) if (count) destination.insert(generation);
  }
  bool Contains(uint64_t generation) const { return counts_.contains(generation); }
  size_t size() const { return counts_.size(); }
  bool valid() const { return valid_; }
  void Reset() { counts_.clear(); valid_ = true; }
 private:
  std::unordered_map<uint64_t, uint64_t> counts_;
  bool valid_ = true;
};
}  // namespace rex::graphics::gta4_native

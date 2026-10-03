#pragma once
#include <cstddef>
#include <cstdint>
#include <iterator>
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
    if (!count && zero_entries_) --zero_entries_;
    ++count; return true;
  }
  // Zero counts stay in the table: the same textures are retained and
  // released for nearly every draw, and erasing them churned hash nodes
  // through the allocator on both render threads. They are pruned in bulk.
  bool Release(uint64_t generation) {
    if (!generation) return true;
    const auto it = counts_.find(generation);
    if (it == counts_.end() || !it->second) { valid_ = false; return false; }
    if (!--it->second && ++zero_entries_ > kPruneThreshold && zero_entries_ * 2 > counts_.size())
      Prune();
    return true;
  }
  void AppendTo(std::unordered_set<uint64_t>& destination) const {
    destination.reserve(destination.size() + counts_.size() - zero_entries_);
    for (const auto& [generation, count] : counts_) if (count) destination.insert(generation);
  }
  bool Contains(uint64_t generation) const {
    const auto it = counts_.find(generation);
    return it != counts_.end() && it->second;
  }
  size_t size() const { return counts_.size() - zero_entries_; }
  bool valid() const { return valid_; }
  void Reset() { counts_.clear(); zero_entries_ = 0; valid_ = true; }
 private:
  static constexpr size_t kPruneThreshold = 4096;
  void Prune() {
    for (auto it = counts_.begin(); it != counts_.end();)
      it = it->second ? std::next(it) : counts_.erase(it);
    zero_entries_ = 0;
  }
  std::unordered_map<uint64_t, uint64_t> counts_;
  size_t zero_entries_ = 0;
  bool valid_ = true;
};
}  // namespace rex::graphics::gta4_native

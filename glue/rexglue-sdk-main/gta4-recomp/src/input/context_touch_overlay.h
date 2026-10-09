#pragma once

#include <rex/ui/imgui_dialog.h>
#include <rex/ui/immediate_drawer.h>
#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>

#include "input/context_touch_draw.h"
#include "input/context_touch_editor_mouse.h"

namespace gta4::input {

class ContextTouchOverlay final : public rex::ui::ImGuiDialog {
 public:
  explicit ContextTouchOverlay(rex::ui::ImGuiDrawer* drawer,
                               rex::ui::ImmediateDrawer* immediate = nullptr,
                               std::filesystem::path icon_directory = {},
                               rex::ui::Window* window = nullptr);
  void SetIconResolver(ContextTouchIconResolver resolver, void* context = nullptr) noexcept;
  bool WantsContinuousRepaint() const override { return repaint_needed_; }

 protected:
  void OnDraw(ImGuiIO& io) override;

 private:
  bool repaint_needed_ = false;
  static bool ResolveIcon(void* context, std::string_view id, ContextTouchIcon* icon);
  rex::ui::ImmediateDrawer* immediate_ = nullptr;
  std::filesystem::path icon_directory_;
  // String-view lookup avoids allocating a std::string for every cached icon draw.
  struct IconHash {
    using is_transparent = void;
    size_t operator()(std::string_view key) const noexcept {
      return std::hash<std::string_view>{}(key);
    }
  };
  struct IconEqual {
    using is_transparent = void;
    bool operator()(std::string_view a, std::string_view b) const noexcept {
      return a == b;
    }
  };
  std::unordered_map<std::string, std::unique_ptr<rex::ui::ImmediateTexture>, IconHash,
                     IconEqual> icons_;
  size_t decoded_icon_bytes_ = 0;
  ContextTouchIconResolver icon_resolver_ = nullptr;
  void* icon_context_ = nullptr;
  std::unique_ptr<ContextTouchEditorMouse> editor_mouse_;
};

}  // namespace gta4::input

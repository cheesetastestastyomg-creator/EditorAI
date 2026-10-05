#include <imgui-cocos.hpp>
#include <imgui.h>

#ifdef GEODE_IS_MOBILE

namespace {
    void applyMobileScale() {
        static ImGuiContext* scaledContext = nullptr;
        auto* ctx = ImGui::GetCurrentContext();
        if (!ctx) return;

        if (scaledContext != ctx) {
            scaledContext = ctx;
            auto& style = ImGui::GetStyle();

            // The panel was already fullscreen on mobile, but its controls
            // and text were still desktop-sized. Scale both the geometry and
            // the font, then add extra touch hit-box padding.
            constexpr float SCALE = 2.0f;
            style.ScaleAllSizes(SCALE);
            style.TouchExtraPadding = ImVec2(8.f, 8.f);
            style.ScrollbarSize = 18.f;
            style.GrabMinSize = 20.f;
            style.FramePadding = ImVec2(16.f, 10.f);
            style.ItemSpacing = ImVec2(14.f, 12.f);
            style.WindowPadding = ImVec2(20.f, 18.f);
            style.ItemInnerSpacing = ImVec2(12.f, 10.f);
            style.FontScaleDpi = SCALE;
        }
    }
}

class $modify(EditorAIMobileImGui, ImGuiCocos) {
    void drawFrame() {
        ImGuiCocos::drawFrame();
        applyMobileScale();
    }
};

#endif

#include "Overlay.h"
#include "AppLayer.h"
#include "Application.h"
#include "Layer.h"
#include "TestLayer.h"
#include "imgui.h"

Overlay::Overlay() : Layer("Overlay", true) {}

void Overlay::OnImGuiRender() {
    ImGuiIO &io = ImGui::GetIO();

    ImGui::Begin("Overlay Transition");
    if (ImGui::Button("Overlay Transition")) {
        auto testLayer = Application::Get().GetLayer<TestLayer>();
        if (testLayer) {
            testLayer->TransitionTo<AppLayer>();
        } else {
            auto appLayer = Application::Get().GetLayer<AppLayer>();
            appLayer->TransitionTo<TestLayer>();
        }
    }
    ImGui::End();
}

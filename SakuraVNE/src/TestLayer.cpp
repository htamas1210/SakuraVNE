#include "TestLayer.h"
#include "AppLayer.h"
#include "Layer.h"
#include "imgui.h"

TestLayer::TestLayer() : Layer("TestLayer", true) {}

void TestLayer::OnImGuiRender() {
    ImGuiIO &io = ImGui::GetIO();

    ImGui::Begin("Layer Transition");
    if (ImGui::Button("Transition")) {
        TransitionTo<AppLayer>();
    }
    ImGui::End();
}

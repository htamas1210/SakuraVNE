#include "AppLayer.h"
#include "Application.h"
#include "Layer.h"
#include "imgui.h"

AppLayer::AppLayer() : Layer("AppLayer", true) {}

void AppLayer::OnImGuiRender() {
    ImGuiIO &io = ImGui::GetIO();
    bool demoWindow = true;
    ImGui::Begin("Framerate");
    ImGui::ShowDemoWindow(&demoWindow);
    ImGui::Text("Application avg %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

    if (ImGui::Button("Quit")) {
        Application::Get().SetRunningState(false);
    }
    ImGui::End();
}

#include "AppLayer.h"
#include "Application.h"
#include "Event.h"
#include "InputEvents.h"
#include "Layer.h"
#include "Log.h"
#include "TestLayer.h"
#include "WindowEvents.h"
#include "imgui.h"
#include <string>

AppLayer::AppLayer() : Layer("AppLayer", true) {}

void AppLayer::OnImGuiRender() {
    ImGuiIO &io = ImGui::GetIO();
    bool demoWindow = true;
    ImGui::Begin("Framerate");
    ImGui::ShowDemoWindow(&demoWindow);
    ImGui::Text("Application avg %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

    if (ImGui::Button("Quit")) {
        SakuraVNE::Application::Get().SetRunningState(false);
    }
    ImGui::End();

    ImGui::Begin("To TestLayer Transition");
    if (ImGui::Button("Transition")) {
        TransitionTo<TestLayer>();
    }
    ImGui::End();
}

void AppLayer::OnEvent(SakuraVNE::Event &event) {
    LOG_INFO("{}", event.ToString());
    SakuraVNE::EventDispatcher dispatcher(event);
    dispatcher.Dispatch<SakuraVNE::MouseButtonPressedEvent>([this](SakuraVNE::MouseButtonPressedEvent &e) { return OnMouseButtonPressed(e); });
    dispatcher.Dispatch<SakuraVNE::MouseMovedEvent>([this](SakuraVNE::MouseMovedEvent &e) { return OnMouseMoved(e); });
    dispatcher.Dispatch<SakuraVNE::WindowClosedEvent>([this](SakuraVNE::WindowClosedEvent &e) { return OnWindowClosed(e); });
}

bool AppLayer::OnMouseButtonPressed(SakuraVNE::MouseButtonPressedEvent &event) { return false; }
bool AppLayer::OnMouseMoved(SakuraVNE::MouseMovedEvent &event) { return false; }
bool AppLayer::OnWindowClosed(SakuraVNE::WindowClosedEvent &event) { return false; }

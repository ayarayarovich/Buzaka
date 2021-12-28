
#include "Buzaka.h"
#include <imgui.h>

class ExampleLayer : public Buzaka::Layer {
public:
    ExampleLayer() : Buzaka::Layer("ExampleLayer") {}

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hey there!");
        ImGui::End();
    }
};

class SandboxApp : public Buzaka::Application {
public:
    SandboxApp() {
        PushLayer(new ExampleLayer());
    }
};

Buzaka::Application* Buzaka::CreateApplication() {
    return new SandboxApp();
}

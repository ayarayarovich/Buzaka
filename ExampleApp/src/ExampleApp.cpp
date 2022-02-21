
#include "Buzaka.h"
#include <imgui.h>
#include <glad/gl.h>

class ExampleLayer : public Buzaka::Layer {
public:
    ExampleLayer() : Buzaka::Layer("ExampleLayer") {}

    void OnAttach() override {
        glClearColor(1, 0, 1, 1);
    }

    void OnUpdate() override {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    virtual void OnImGuiRender() override
    {
//        ImGui::Begin("Test");
//        ImGui::Text("Hey there!");
//        ImGui::End();
        bool show = true;
        ImGui::ShowMetricsWindow(&show);
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

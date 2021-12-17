
#include "Buzaka.h"
#include <glad/glad.h>

class ExampleLayer : public Buzaka::Layer {
public:
    ExampleLayer() : Buzaka::Layer("ExampleLayer") {}

    void OnEvent(Buzaka::Event& event) override {
        BZ_TRACE("{0}", event);
    }

    void OnUpdate() override
    {
        glClearColor(1.f, 0.3f, 0.5f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

class SandboxApp : public Buzaka::Application {
public:
    SandboxApp() {
        PushLayer(new ExampleLayer());
        PushOverlay(new Buzaka::ImGuiLayer());
    }
};

Buzaka::Application* Buzaka::CreateApplication() {
    return new SandboxApp();
}

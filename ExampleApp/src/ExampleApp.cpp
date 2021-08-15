
#include "Buzaka.h"

class ExampleLayer : public Buzaka::Layer {
public:
    ExampleLayer() : Buzaka::Layer("ExampleLayer") {}

    void OnEvent(Buzaka::Event& event) override {
        Buzaka::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Buzaka::MouseButtonPressedEvent>([this](Buzaka::MouseButtonPressedEvent& event) -> bool {
            BZ_INFO("{0}: {1} handled", GetDebugName(), event.GetName());
            return true;
        });
    }
};

class ExampleOverlay : public Buzaka::Layer {
public:
    ExampleOverlay() : Buzaka::Layer("ExampleOverlay") {}

    void OnEvent(Buzaka::Event& event) override {
        Buzaka::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Buzaka::MouseButtonPressedEvent>([this](Buzaka::MouseButtonPressedEvent& event) -> bool {
            BZ_INFO("{0}: {1} hasn't been handled", GetDebugName(), event.GetName());
            return false;
        });
    }
};

class SandboxApp : public Buzaka::Application {
public:
    SandboxApp() {
        PushLayer(new ExampleLayer());
        PushOverlay(new ExampleOverlay());
    }
};

Buzaka::Application* Buzaka::CreateApplication() {
    BZ_INFO("ExampleApp creation.")
    return new SandboxApp();
}

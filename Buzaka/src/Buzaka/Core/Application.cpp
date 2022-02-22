#include "pch/bzpch.h"

#include "Application.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Buzaka {

    Application* Application::s_Instance = nullptr;

    Application::Application() {
        BZ_CORE_ASSERT(s_Instance == nullptr, "Application instance already exists!");
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BZ_BIND_EVENT_FUNC(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    };

    Application::~Application() = default;

    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BZ_BIND_EVENT_FUNC(Application::OnWindowClose));

        for (auto rit = m_LayerStack.rbegin(); rit != m_LayerStack.rend(); rit++) {
            (*rit)->OnEvent(event);
            if (event.IsHandled())
                break;
        }
    }

    void Application::Run() {
        while (m_Running) {
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_ImGuiLayer->Begin();
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &event) {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay) {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }
}

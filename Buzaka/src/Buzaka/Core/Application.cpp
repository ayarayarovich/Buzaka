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
    };

    Application::~Application() = default;

    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BZ_BIND_EVENT_FUNC(Application::OnWindowClose));

        for (Layer* layer : std::ranges::reverse_view(m_LayerStack)) {
          layer->OnEvent(event);
          if (event.IsHandled())
              break;
        };
    }

    void Application::Run() {
        while (m_Running) {
            glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

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

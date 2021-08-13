#include "Application.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Buzaka {

#define BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));
    };

    Application::~Application() = default;

    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));

        BZ_CORE_TRACE("{0}", event);
    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &event) {
        m_Running = false;
        return true;
    }
}
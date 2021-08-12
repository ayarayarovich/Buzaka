#include "Application.h"
#include "Log.h"
#include "Events.h"

namespace Buzaka {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
    };
    Application::~Application() = default;

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }
}
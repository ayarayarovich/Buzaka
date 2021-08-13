#include "WindowsWindow.h"
#include "Buzaka/Core/Log.h"
#include "Buzaka/Core/Assert.h"
#include "Buzaka/Core/Events.h"

namespace Buzaka {

    static bool s_GLFWInitialized = false;
    static void GLFWErrorCallback(int error, const char* description) {
        BZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProps &props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props) {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        BZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            int success = glfwInit();
            BZ_CORE_ASSERT(success, "GLFW initialization failed.");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
           WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

           windowData.Width = width;
           windowData.Height = height;

           WindowResizeEvent event(width, height);
           windowData.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            windowData.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    windowData.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    windowData.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    windowData.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
           WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

           switch (action) {
               case GLFW_PRESS:
               {
                   MouseButtonPressedEvent event(button);
                   windowData.EventCallback(event);
                   break;
               }
               case GLFW_RELEASE:
               {
                   MouseButtonReleasedEvent event(button);
                   windowData.EventCallback(event);
                   break;
               }
           }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            windowData.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            windowData.EventCallback(event);
        });

        glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xOffset, int yOffset) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            WindowMovedEvent event(xOffset, yOffset);
            windowData.EventCallback(event);
        });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
            WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);

            switch (focused) {
                case GLFW_TRUE:
                {
                    WindowGotFocusEvent event;
                    windowData.EventCallback(event);
                    break;
                }
                case GLFW_FALSE:
                {
                    WindowLostFocusEvent event;
                    windowData.EventCallback(event);
                    break;
                }
            }
        });
    }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const {
        return m_Data.VSync;
    }

    void WindowsWindow::Shutdown() {
        BZ_CORE_INFO("Destroying window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);
        glfwDestroyWindow(m_Window);
    }

}
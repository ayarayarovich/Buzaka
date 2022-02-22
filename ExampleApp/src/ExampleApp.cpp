
#include "Buzaka.h"
#include <imgui.h>
#include <glad/gl.h>

class ExampleLayer : public Buzaka::Layer {
public:
    ExampleLayer() : Buzaka::Layer("ExampleLayer") {}

    void OnUpdate() override {
        glClearColor(m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OnEvent(Buzaka::Event &event) override {
        Buzaka::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Buzaka::KeyReleasedEvent>([&](Buzaka::KeyReleasedEvent& e) {
            if (e.WithCtrl() && e.GetKeyCode() == BZ_KEY_O) {
                m_ShowDemoWindow ^= true;
                return true;
            }

            if (e.WithCtrl() && e.GetKeyCode() == BZ_KEY_W) {
                m_ShowAnotherWindow ^= true;
                return true;
            }

            return false;
        });
    }

    virtual void OnImGuiRender() override
    {
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!", &m_ShowConsoleWindow, ImGuiWindowFlags_MenuBar);                          // Create a window called "Hello, world!" and append into it.

            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("Windows"))
                {
                    if (ImGui::MenuItem("Demo window", "CTRL+O"))
                    {
                        m_ShowDemoWindow = !m_ShowDemoWindow;
                    }
                    if (ImGui::MenuItem("Another window", "CTRL+W"))
                    {
                        m_ShowAnotherWindow = !m_ShowAnotherWindow;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            ImGui::Text("This is some useful text.");

            ImGui::Checkbox("Show Demo Window", &m_ShowDemoWindow);
            ImGui::Checkbox("Show Another Window", &m_ShowAnotherWindow);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&m_ClearColor); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        if (m_ShowDemoWindow) {
            ImGui::ShowDemoWindow(&m_ShowDemoWindow);
        }

        if (m_ShowAnotherWindow)
        {
            ImGui::Begin("Another Window", &m_ShowAnotherWindow);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                m_ShowAnotherWindow = false;
            ImGui::End();
        }
    }
  private:
    ImVec4 m_ClearColor = ImVec4(1.f, 1.f, 0.f, 1.f);
    bool m_ShowDemoWindow = false;
    bool m_ShowAnotherWindow = false;
    bool m_ShowConsoleWindow = true;
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

#pragma once

#include "Buzaka/Core/Layer.h"
#include "Buzaka/Core/Events.h"
#include "imgui.h"

namespace Buzaka {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent( Event& event ) override;

        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnWindowResizedEvent(WindowResizeEvent& e);

    private:
        float m_Time = 0.f;
    };
}

#pragma once

#include "Buzaka/Core/Layer.h"
#include "Buzaka/Core/Events.h"
#include "imgui.h"

namespace Buzaka {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        virtual ~ImGuiLayer() override;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.f;
    };
}

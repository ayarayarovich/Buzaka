#pragma once

#include "pch/bzpch.h"
#include "Events.h"

namespace Buzaka {

    class Layer {
    public:
        explicit Layer(std::string name = "Layer") : m_DebugName(std::move(name)) {};
        virtual ~Layer() = default;

        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate();
        virtual void OnEvent(Event& event);

        virtual void OnImGuiRender();

        [[nodiscard]] inline std::string_view GetDebugName() const { return m_DebugName; };

    private:
        std::string m_DebugName;
    };

}

#pragma once

#include "pch/bzpch.h"
#include "Buzaka/Events/Event.h"

namespace Buzaka {
    struct WindowProps {
        std::string_view Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string_view title = "Buzaka Engine",
                    unsigned int width = 864,
                    unsigned int height = 486)
                    : Title(title), Width(width), Height(height) {}
    };

    class Window {
    public:
        using EventCallbackFunc = std::function<void(Event&)>;
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFunc& callbackFunc) = 0;
        virtual void SetVSync(bool enabled) = 0;
        [[nodiscard]] virtual bool IsVSync() const = 0;

        [[nodiscard]] virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };

}
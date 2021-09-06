#pragma once

#include "Event.h"

namespace Buzaka {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        [[nodiscard]] inline unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] inline unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ')';
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory_Application)
        EVENT_CLASS_TYPE(EventType::WindowResize)

    private:
        unsigned int m_Width, m_Height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory_Application)
        EVENT_CLASS_TYPE(EventType::WindowClose)
    };

    class WindowGotFocusEvent : public Event {
    public:
        WindowGotFocusEvent() = default;

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowGotFocusEvent";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory_Application)
        EVENT_CLASS_TYPE(EventType::WindowGotFocus)
    };

    class WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() = default;

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowLostFocusEvent";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory_Application)
        EVENT_CLASS_TYPE(EventType::WindowLostFocus)
    };

    class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(int xOffset, int yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        [[nodiscard]] inline int GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline int GetYOffset() const { return m_YOffset; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowMovedEvent: (" << m_XOffset << ", " << m_YOffset << ')';
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory_Application)
        EVENT_CLASS_TYPE(EventType::WindowMoved)

    private:
        int m_XOffset, m_YOffset;
    };
}

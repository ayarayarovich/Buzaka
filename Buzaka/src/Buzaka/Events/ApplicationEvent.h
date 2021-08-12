#pragma once

#include "Event.h"

namespace Buzaka {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ')';
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
        EVENT_CLASS_TYPE(EventType::WindowResize)

    private:
        unsigned int m_Width, m_Height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
        EVENT_CLASS_TYPE(EventType::WindowClose)
    };

    class WindowGotFocusEvent : public Event {
    public:
        WindowGotFocusEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
        EVENT_CLASS_TYPE(EventType::WindowGotFocus)
    };

    class WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
        EVENT_CLASS_TYPE(EventType::WindowLostFocus)
    };

    class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(int xOffset, int yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        inline int GetXOffset() const { return m_XOffset; }
        inline int GetYOffset() const { return m_YOffset; }

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
        EVENT_CLASS_TYPE(EventType::WindowMoved)

    private:
        int m_XOffset, m_YOffset;
    };
}
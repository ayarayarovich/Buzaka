#pragma once

#include "Event.h"

namespace Buzaka {

    class KeyEvent : public Event {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory_Input | EventCategory_Keyboard)

    protected:
        explicit KeyEvent(int keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        [[nodiscard]] inline int GetRepeatCount() const { return m_RepeatCount; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyPressed)

    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        explicit KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyReleased)

    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode)
        {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyTyped);
    };

}

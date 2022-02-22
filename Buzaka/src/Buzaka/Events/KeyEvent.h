#pragma once

#include "Event.h"
#include "Buzaka/Core/KeyCodes.h"

namespace Buzaka {

    class KeyEvent : public Event {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }

        [[nodiscard]] inline bool WithCtrl() const { return m_Mods & BZ_MOD_CONTROL; }
        [[nodiscard]] inline bool WithShift() const { return m_Mods & BZ_MOD_SHIFT; }
        [[nodiscard]] inline bool WithAlt() const { return m_Mods & BZ_MOD_ALT; }

        EVENT_CLASS_CATEGORY(EventCategory_Input | EventCategory_Keyboard)

    protected:
        explicit KeyEvent(int keycode, int mods = 0)
            : m_KeyCode(keycode), m_Mods(mods) {}

        int m_KeyCode;
        int m_Mods;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount, int mods)
            : KeyEvent(keycode, mods), m_RepeatCount(repeatCount) {}

        [[nodiscard]] inline int GetRepeatCount() const { return m_RepeatCount; }

        [[nodiscard]] inline bool WithCtrl() const { return m_Mods & BZ_MOD_CONTROL; }
        [[nodiscard]] inline bool WithShift() const { return m_Mods & BZ_MOD_SHIFT; }
        [[nodiscard]] inline bool WithAlt() const { return m_Mods & BZ_MOD_ALT; }


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
        explicit KeyReleasedEvent(int keycode, int mods)
            : KeyEvent(keycode, mods) {}

        [[nodiscard]] inline bool WithCtrl() const { return m_Mods & BZ_MOD_CONTROL; }
        [[nodiscard]] inline bool WithShift() const { return m_Mods & BZ_MOD_SHIFT; }
        [[nodiscard]] inline bool WithAlt() const { return m_Mods & BZ_MOD_ALT; }


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

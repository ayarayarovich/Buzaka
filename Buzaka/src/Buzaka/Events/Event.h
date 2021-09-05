#pragma once

#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return type; } \
                                virtual EventType GetEventType() const override { return GetStaticType(); }  \
                                virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

namespace Buzaka {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowGotFocus, WindowLostFocus, WindowMoved,
        // AppTick, AppUpdate, AppRender, - maybe going to be implemented in the future.
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        EventCategoryNone = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput       = 1 << 1,
        EventCategoryKeyboard    = 1 << 2,
        EventCategoryMouse       = 1 << 3,
        EventCategoryMouseButton = 1 << 4
    };

    class Event {
        friend class EventDispatcher;
    public:
        [[nodiscard]] virtual EventType GetEventType() const = 0;
        [[nodiscard]] virtual const char* GetName() const = 0;
        [[nodiscard]] virtual int32_t GetCategoryFlags() const = 0;
        [[nodiscard]] virtual std::string ToString() const { return GetName(); }

        [[nodiscard]] bool IsInCategory(EventCategory category) const {
            return GetCategoryFlags() & category;
        }

        [[nodiscard]] bool IsHandled() const { return m_Handled; }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher {
        template<class EventClass>
        using EventListenerFunc = std::function<bool(EventClass&)>;
    public:
        explicit EventDispatcher(Event& event)
            : m_Event(event) {}

        template<class EventClass>
        bool Dispatch(EventListenerFunc<EventClass> func) {
            if (m_Event.GetEventType() == EventClass::GetStaticType()) {
                m_Event.m_Handled = func(static_cast<EventClass&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event) {
        return os << event.ToString();
    }

}

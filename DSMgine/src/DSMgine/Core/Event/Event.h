#pragma once

#include "DSMgine/Core/Base.h"

#include <sstream>
#include <functional>

namespace DSMgine
{
	// Events are currently blocking, so when an event occurs, it must
	// immediately get dispatched and dealt with right then and there.
	// In future, it would be better to buffer events and process them
	// when we're doing other updating things.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// We have a lot of events, and because of this we don't want to have
	// to get (for example) every individual input-related, or window
	// related events. It would be much simpler categorizing the events.
	enum EventCategory
	{
		// We use a bit field here so that events can fit into multiple categories
		None = BIT(0),
		EventCategoryApplication = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); } // Meant for debugging only

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// By using |= instead of =, once event.Handled has been set to true, it'll never be reset to false
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	class EmptyEvent : public Event
	{
	public:
		EmptyEvent() = default;
		virtual ~EmptyEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Event: Empty";
			return ss.str();
		}

		// This ...
			//virtual int getCategoryFlags() const override { return None; }
		// Into this ...
		EVENT_CLASS_CATEGORY(None);

		// This ...
			//static EventType getStaticType() { return EventType::None; }
			//virtual EventType getEventType() const override { return getStaticType(); }
			//virtual const char* getName() const override { return "None"; }
		// Into this ...
		EVENT_CLASS_TYPE(None);
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}
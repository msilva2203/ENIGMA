#pragma once

#include "Enigma.h"
#include "Enigma/Core.h"

namespace Enigma
{

	enum class EEventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseMoved, MouseScroll, MouseButtonPressed, MouseButtonReleased
	};

	enum EEventCategory
	{
		None = 0,
		Input		= BIT(0),
		Keyboard	= BIT(1),
		Mouse		= BIT(2)
	};

	/*
		* Base Event class
		* Every event type inherits from this class
	*/
	class ENIGMA_API FEvent
	{
	public:
		virtual EEventType GetEventType() const = 0;
		virtual int32 GetCategoryFlags() const = 0;

		inline bool IsInCategory(const EEventCategory Category)
		{
			return GetCategoryFlags() & Category;
		}

	protected:
		bool Handled = false;

	};

#define EVENT_CLASS_TYPE(type) static EEventType GetStaticEventType() { return type; }\
							virtual EEventType GetEventType() const override { return GetStaticEventType(); }

#define EVENT_CLASS_CATEGORY(category)	virtual int32 GetCategoryFlags() const override { return category; }
}
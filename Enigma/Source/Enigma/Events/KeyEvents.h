#pragma once

#include "Event.h"

namespace Enigma
{
	/*
		* Key Event class
		* Is parent to Key Pressed Event class and Key Released Event
	*/
	class ENIGMA_API FKeyEvent : public FEvent
	{
	public:
		EVENT_CLASS_CATEGORY(EEventCategory::Input | EEventCategory::Keyboard)

		inline int32 GetKeyCode() const { return KeyCode; }

	protected:
		FKeyEvent(int32 KeyCode) :
			KeyCode(KeyCode) {}

		int32 KeyCode;
		
	};

	/*
		* Key Pressed Event class 
		* Inherits from Key Event Class
	*/
	class ENIGMA_API FKeyPressedEvent : public FKeyEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::KeyPressed)

		FKeyPressedEvent(int32 KeyCode, int32 RepeatCount) :
			FKeyEvent(KeyCode), RepeatCount(RepeatCount) {}

		inline int32 GetRepeatCount() const { return RepeatCount; }

	protected:
		int32 RepeatCount;

	};

	/*
		* Key Released Event class
		* Inherits from Key Event Class
	*/
	class ENIGMA_API FKeyReleasedEvent : public FKeyEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::KeyReleased)

		FKeyReleasedEvent(int32 KeyCode) :
			FKeyEvent(KeyCode) {}

	protected:

	};

}
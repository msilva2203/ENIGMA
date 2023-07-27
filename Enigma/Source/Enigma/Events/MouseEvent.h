#pragma once

#include "Event.h"

namespace Enigma
{

	/*
		* Mouse Moved Event class 
	*/
	class ENIGMA_API FMouseMovedEvent : public FEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::MouseMoved)
		EVENT_CLASS_CATEGORY(EEventCategory::Input | EEventCategory::Mouse)

		FMouseMovedEvent(int32 xPos, int32 yPos) :
			xPos(xPos), yPos(yPos) {}

		inline int32 GetMouseX() const { return xPos; }
		inline int32 GetMouseY() const { return yPos; }

	private:
		int32 xPos, yPos;

	};

	/*
		* Mouse Scroll Event class
	*/
	class ENIGMA_API FMouseScrollEvent : public FEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::MouseScroll)
		EVENT_CLASS_CATEGORY(EEventCategory::Input | EEventCategory::Mouse)

		FMouseScrollEvent(float xOffset, float yOffset) : 
			xOffset(xOffset), yOffset(yOffset) {}

		inline float GetOffsetX() const { return xOffset; }
		inline float GetOffsetY() const { return yOffset; }

	private:
		float xOffset, yOffset;

	};

	/*
		* Mouse Button Event class
		* Is Parent to Mouse Button Pressed Event class and Mouse Button Released Event class
	*/
	class ENIGMA_API FMouseButtonEvent : public FEvent
	{
	public:
		EVENT_CLASS_CATEGORY(EEventCategory::Input | EEventCategory::Mouse)

		inline int32 GetKeyCode() const { return KeyCode; }

	protected:
		FMouseButtonEvent(int32 KeyCode) :
			KeyCode(KeyCode) {}

		int32 KeyCode;
	};

	/*
		* Mouse Button Pressed Event class
		* Inherits from Mouse Button Event class
	*/
	class ENIGMA_API FMouseButtonPressedEvent : public FMouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::MouseButtonPressed)

		FMouseButtonPressedEvent(int32 KeyCode) :
			FMouseButtonEvent(KeyCode) {}

	private:

	};

	/*
		* Mouse Button Released Event class
		* Inherits from Mouse Button Event class
	*/
	class ENIGMA_API FMouseButtonReleasedEvent : public FMouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(EEventType::MouseButtonReleased)

		FMouseButtonReleasedEvent(int32 KeyCode) :
			FMouseButtonEvent(KeyCode) {}

	private:

	};

}
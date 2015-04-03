#pragma once

#include "header.h"

namespace MyEvent
{
	public delegate void MyEventHandler();

	public ref struct SomeEvent
	{
	private:
		event MyEventHandler^ Event;

	public:		
		void EventOn()
		{
			Event();
		}
		void AddEvent(MyEventHandler^ tmp_event)
		{
			Event += tmp_event;
		}
	};
}
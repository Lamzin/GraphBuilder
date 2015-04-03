namespace MyEvent
{
	delegate void MyEventChangeSettings();

	public ref class ChangeSettings
	{
	public:
		event MyEventChangeSettings^ Event;
		
		void EventON()
		{
			Event();
		}
	};
}
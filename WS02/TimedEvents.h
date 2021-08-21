#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>

namespace sdds {

	class TimedEvents {
		int currentStorage = 0;
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		struct Event {
			std::string EventName;
			std::string UnitsOfTime;
			std::chrono::duration<long, std::nano> Duration;
		} arrStruct[10];
	public:
		TimedEvents();
		TimedEvents(const TimedEvents& right);
		TimedEvents& operator=(const TimedEvents& right);
		~TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name = nullptr);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& right);
	};
}

#endif
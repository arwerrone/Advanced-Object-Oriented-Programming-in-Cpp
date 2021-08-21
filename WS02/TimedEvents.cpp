#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include "TimedEvents.h"

using namespace std;
namespace sdds {

	TimedEvents::TimedEvents(){
		currentStorage = 0;
	}

	TimedEvents::TimedEvents(const TimedEvents& right) {
		*this = right;
	}

	TimedEvents& TimedEvents::operator=(const TimedEvents& right) {
		if (this != &right) {
			currentStorage = right.currentStorage;
			for (int i = 0; i < right.currentStorage; i++) {
				arrStruct[i].EventName = right.arrStruct[i].EventName;
				arrStruct[i].UnitsOfTime= right.arrStruct[i].UnitsOfTime;
				arrStruct[i].Duration = right.arrStruct[i].Duration;
			}
		}
		return *this;
	}

	TimedEvents::~TimedEvents() {	}

	void TimedEvents::startClock() {
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name) {
		arrStruct[currentStorage].EventName = name;
		arrStruct[currentStorage].UnitsOfTime = "nanoseconds";
		arrStruct[currentStorage].Duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		currentStorage++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& right) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < right.currentStorage ;i++) {
			os.width(21);
			os.setf(ios::left);
			os << right.arrStruct[i].EventName;
			os.width(13);
			os.setf(ios::right);
			os << right.arrStruct[i].Duration.count();
			os << " ";
			os << right.arrStruct[i].UnitsOfTime;
			os << endl;
			os.unsetf(ios::right);
		}
		os << "--------------------------" << endl;
		return os;
	}

}
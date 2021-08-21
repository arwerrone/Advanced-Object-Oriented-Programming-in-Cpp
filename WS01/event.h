#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
#include <iostream>

extern unsigned int g_sysClock;
namespace sdds {

	class Event {
		char* m_description = nullptr;
		int m_eventstart = 0;
		void descset(const char* value = nullptr);
	public:
		Event();
		Event(const Event& right);
		Event& operator=(const Event& right);
		~Event();
		void display() const;
		void set(char arr[] = nullptr);
		
	};

}

#endif

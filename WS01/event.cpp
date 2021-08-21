#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"


//extern unsigned int g_sysClock;
unsigned int g_sysClock = 0;
namespace sdds {

	Event::Event() {
		m_description = nullptr;
		m_eventstart = 0;
	}

	Event::Event(const Event& right) {
		operator=(right);
	}

	Event& Event::operator=(const Event& right) {
		if (this != &right) {
			if (right.m_description != nullptr) {
				m_eventstart = right.m_eventstart;
				descset(right.m_description);
			}
			else {
				delete[] m_description;
				m_description = nullptr;
				m_eventstart = 0;
			}
		}
		return *this;
	}

	Event::~Event() {
		delete[] m_description;
		m_description = nullptr;
	}

	void Event::display() const{
		static int counter = 0;
		counter++;

		if (m_description != nullptr) {
			int hh = 0, mm = 0;
			int ss = m_eventstart;
			while (ss >= 60) {
				ss -= 60;
				mm++;
			}
			while (mm >= 60) {
				mm -= 60;
				hh++;
				if (hh == 24) {
					hh = 0;
				}
			}
			std::cout.width(2);
			std::cout.setf(std::ios::right);
			std::cout.fill(' ');
			std::cout << counter << ". ";
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << hh << ":";
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << mm << ":";
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << ss;
			std::cout << " => " << m_description << std::endl;
		}
		else {
			std::cout.width(2);
			std::cout.setf(std::ios::right);
			std::cout.fill(' ');
			std::cout << counter << ". | No Event |" << std::endl;
		}

	}

	void Event::set(char arr[]) {
		if (arr != nullptr && arr[0] != '\0' && g_sysClock >= 0 && g_sysClock <= 86400) {
			m_eventstart = g_sysClock;
			descset(arr);
		}
		else {
			delete[] m_description;
			m_description = nullptr;
		}
	}
	//descset function sets the description of event dynamically, this allows reusage and less coding
	void Event::descset(const char* value) {
		delete[] m_description;
		m_description = nullptr;
		m_description = new char[strlen(value) + 1];
		strcpy(m_description,value);
	}

}
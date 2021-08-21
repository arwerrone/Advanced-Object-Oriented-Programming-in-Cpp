#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include<iostream>
#include<string>

namespace sdds {
	class Reservation{
		std::string m_id {""};
		std::string m_name {""};
		std::string m_email {""};
		std::size_t m_numOfPeople {0};
		std::size_t m_day {0};
		std::size_t m_hour {0};
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};

}

#endif
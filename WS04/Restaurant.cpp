#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds {

	Restaurant::Restaurant(const sdds::Reservation* reservations[], size_t cnt) {
		m_reservation = new Reservation[cnt];
		m_resNum = cnt;
		for (size_t i = 0; i < cnt; i++) {
			m_reservation[i] = *reservations[i];
		}

	}

	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			m_resNum = src.m_resNum;
			delete[] m_reservation;
			m_reservation = new Reservation[m_resNum];
			for (size_t i = 0; i < m_resNum; i++) {
				m_reservation[i] = src.m_reservation[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept {
		if (this != &src) {
			m_resNum = src.m_resNum;
			delete[] m_reservation;
			m_reservation = src.m_reservation;
			src.m_reservation = nullptr;
			src.m_resNum = 0;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		delete[] m_reservation;
		m_reservation = nullptr;
	}

	size_t Restaurant::size() const {
		return m_resNum;
	}

	ostream& operator<<(ostream& os, Restaurant& right) {
		static size_t CALL_CNT;
		++CALL_CNT;

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant " << "(" << CALL_CNT << ")" <<std::endl;
		os << "--------------------------" << std::endl;

		if (right.m_resNum == 0) {
			os << "This restaurant is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < right.m_resNum; i++) {
				os << right.m_reservation[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}

}
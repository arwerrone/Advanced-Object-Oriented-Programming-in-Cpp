#include <iostream>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {

	ConfirmationSender::ConfirmationSender() : m_reservation{ nullptr }, m_resNum{0}{}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {	////Possivel erro
		if (this != &src) {
			m_resNum = src.m_resNum;
			delete[] m_reservation;										
			m_reservation = new const Reservation* [m_resNum];
			for (size_t i = 0; i < m_resNum; i++) {
				m_reservation[i] = src.m_reservation[i];
			}

		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept {
		if (this != &src) {
			m_resNum = src.m_resNum;
			delete[] m_reservation;
			m_reservation = src.m_reservation;
			src.m_reservation = nullptr;
			src.m_resNum = 0;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reservation;
		m_reservation = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool ok = false;
		for (size_t i = 0; i < m_resNum; i++) {
			if (m_reservation[i] == &res) {
				ok = true;
			}
		}
		if (ok == false) {
			const Reservation** temp = nullptr;
			temp = new const Reservation* [m_resNum + 1];
			for (size_t i = 0; i < m_resNum; i++) {
				temp[i] = m_reservation[i];
			}
			temp[m_resNum] = &res;
			m_resNum++;
			delete[] m_reservation;
			m_reservation = temp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool ok = false;
		size_t indexx = -1 ;
		for (size_t i = 0; i < m_resNum; i++) {
			if (m_reservation[i] == &res) {
				ok = true;
				indexx = i;
				i = m_resNum;	//kill loop
			}
		}
		if (ok) {
			const Reservation** temp = nullptr; // {}
			temp = new const Reservation* [m_resNum - 1];	//resize, se der pau deletar 
			for (size_t i = 0; i < (m_resNum - 1); i++) {
				if (i < indexx) {
					temp[i] = m_reservation[i];
				}
				else {
					temp[i] = m_reservation[i + 1];
				}
			}
			--m_resNum;										//resize, se der pau deletar 
			delete[] m_reservation;
			m_reservation = temp;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& right) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (right.m_resNum == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (size_t i = 0; i < right.m_resNum; i++) {
				if (right.m_reservation[i] != nullptr) {
					os << *right.m_reservation[i];
				}
			}
		}
		os << "--------------------------" << endl;

		return os;
	}

}
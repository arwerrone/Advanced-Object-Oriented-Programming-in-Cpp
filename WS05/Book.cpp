#include <iostream>
#include "Book.h"

namespace sdds {

	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0;
		m_desc = "";
	}

	const std::string& Book::author() const {
		return m_author;
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	const std::string& Book::description() const {
		return m_desc;
	}

	void Book::exterminate(std::string& str) {
		bool ok = false;

		while (!ok)
		{
			if (str[0] == ' ') {
				str.erase(0, 1);
			}
			else if (str[str.length() - 1] == ' ') {
				str.erase(str.length() - 1, str.length());
			}
			else {
				ok = true;
			}
		}
	}

	Book::Book(const std::string& strBook) {
		std::string temp = strBook;

		m_author = temp.substr(0, temp.find(','));
		exterminate(m_author);
		temp.erase(0, temp.find(',') + 1);

		m_title = temp.substr(0, temp.find(','));
		exterminate(m_title);
		temp.erase(0, temp.find(',') + 1);

		m_country = temp.substr(0, temp.find(','));
		exterminate(m_country);
		temp.erase(0, temp.find(',') + 1);

		m_price = std::stod(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);

		m_year = std::stoi(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);

		m_desc = temp;
		exterminate(m_desc);
	}

	std::ostream& operator<< (std::ostream& os, const Book& book) {
		os.setf(std::ios::right);
		os.width(20);
		os << book.author() << " | ";
		os.width(22);
		os << book.title() << " | ";
		os.width(5);
		os << book.country() << " | ";
		os.width(4);
		os << book.year() << " | ";
		os.width(6);
		os.precision(2);
		os.setf(std::ios::fixed);
		os << book.m_price << " | ";
		os << book.description() << std::endl;
		
		return os;
	}

}

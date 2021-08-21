#include <iostream>
#include "Movie.h"

namespace sdds {

	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_desc = "";
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	void Movie::exterminate(std::string& str) {
		bool ok = false;

		while (!ok)
		{
			if (str[0] == ' '){
				str.erase(0, 1);
			}
			else if (str[str.length() - 1] == ' '){
				str.erase(str.length() - 1, str.length());
			}
			else{
				ok = true;
			}
		}
	}

	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;

		m_title = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		m_year = std::stoi(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);

		m_desc = temp;

		exterminate(m_title);
		exterminate(m_desc);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os.width(40);
		os.setf(std::ios::right);
		os << movie.m_title << " | ";
		os.unsetf(std::ios::right);
		os.width(4);
		os << movie.m_year << " | ";
		os.setf(std::ios::left);
		os << movie.m_desc << std::endl;

		return os;
	}

}

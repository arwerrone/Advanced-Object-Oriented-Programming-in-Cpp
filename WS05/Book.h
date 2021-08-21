#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {

	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{ 0 };
		double m_price{ 0 };
		std::string m_desc{};
		void exterminate(std::string& str);
	public:
		Book();
		const std::string& author() const;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const std::string& description() const;
		Book(const std::string& strBook);
		friend std::ostream& operator<< (std::ostream& os, const Book& book);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}

	};

}

#endif

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{ 0 };
		std::string m_desc{};
		void exterminate(std::string& str);
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}
		
	};

}

#endif
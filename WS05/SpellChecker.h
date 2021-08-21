#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds {
	constexpr size_t MAX_WORD = 6;
	class SpellChecker {
		std::string m_badWords[MAX_WORD];
		std::string m_goodWords[MAX_WORD];
		size_t m_cnt[MAX_WORD]{0};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;

	};

}

#endif
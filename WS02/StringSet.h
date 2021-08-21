#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <string>

namespace sdds {
	
	class StringSet {
		int numOfStr = 0;
		std::string* name = nullptr;
	public:
		StringSet();
		StringSet(const char* filename);
		size_t size() const;
		std::string operator[](size_t) const;

		StringSet(const StringSet& right);
		StringSet& operator=(const StringSet& right);
		StringSet(StringSet&& right);
		StringSet& operator=(StringSet&& right);
	};

}

#endif
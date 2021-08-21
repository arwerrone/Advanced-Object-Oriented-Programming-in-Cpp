#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "StringSet.h"

using namespace std;
namespace sdds {

	StringSet::StringSet() :name(nullptr) {
		numOfStr = 0;
	}

	StringSet::StringSet(const char* filename) {
		ifstream fin(filename);
		string str;

		getline(fin, str, ' ');

		for (int i = 0; fin; i++) {
			str = "'\0'";
			getline(fin, str, ' ');
			numOfStr++;
		}
		name = new string[numOfStr + 1];
		fin.clear();
		fin.seekg(0, ios::beg);
		for (int i = 0; i < numOfStr && fin; i++) {
			getline(fin, name[i], ' ');
		}

	}

	size_t StringSet::size() const {
		return numOfStr;
	}

	std::string StringSet::operator[](size_t index) const {
		string toret = "";
		if (index < size() && index >=0) {
			toret = name[index];
		}
		return toret;
	}

	StringSet::StringSet(const StringSet& right) {
		*this = right;
	}

	StringSet& StringSet::operator=(const StringSet& right) {
		if (this != &right) {
			numOfStr = right.numOfStr;
			name = new string[right.numOfStr];
			for (int i = 0; i < right.numOfStr; i++) {
				name[i] = right.name[i];
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& right) {
		*this = std::move(right);
	}

	StringSet& StringSet::operator=(StringSet&& right) {
		if (this != &right) {
			numOfStr = right.numOfStr;
			name = right.name;
			right.numOfStr = 0;
			right.name = nullptr;
		}
		return *this;
	}

}
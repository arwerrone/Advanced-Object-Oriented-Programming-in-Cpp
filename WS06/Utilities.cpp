#include <cstring>
#include <sstream>
#include <iostream>
#include "Utilities.h"

using namespace std;
namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		Vehicle* toret = nullptr;
		string temp;
		char type = '\0';
		getline(in, temp);
		std::stringstream ss(temp);
		ss >> type;

		if (!temp.empty()) {
			if (type == 'C' || type == 'c') {
				toret = new Car(ss);
			}
			else if (type == 'R' || type == 'r') {
				toret = new Racecar(ss);
			}
			else {
				throw type;
			}
		}
		else {
			toret = nullptr;
		}
		return toret;

	}


}
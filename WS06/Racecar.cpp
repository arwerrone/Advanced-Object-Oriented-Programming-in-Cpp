#include <cstring>
#include <iostream>
#include <iomanip>
#include "Racecar.h"

using namespace std;
namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {
		string temp;
		getline(in, temp, '\n');
		m_booster = std::stod(temp);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}

}
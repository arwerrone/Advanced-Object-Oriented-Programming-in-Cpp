#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {
		std::string m_make{};
		std::string m_cond{};
		double m_speed{};
	public:
		Car();
		Car(std::istream& fin);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
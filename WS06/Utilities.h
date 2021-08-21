#ifndef SDDS_UTILITY_H
#define SDDS_UTILITY_H
#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}

#endif
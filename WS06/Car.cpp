#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Car.h"

using namespace std;
namespace sdds {

	Car::Car() : m_make{ "" }, m_cond{ "" }, m_speed{ 0.0 }{}

	Car::Car(std::istream& fin) {
		string tag;
		string speed;
		string condition;
		string makerr;

		getline(fin, tag, ',');
		getline(fin, makerr, ',');
		getline(fin, condition, ',');
		getline(fin, speed, ',');
	
		makerr.erase(0, makerr.find_first_not_of(' '));
		makerr.erase(makerr.find_last_not_of(' ') + 1);
		m_make = makerr;

		condition.erase(0, condition.find_first_not_of(' '));
		condition.erase(condition.find_last_not_of(' ') + 1);

		speed.erase(0, speed.find_first_not_of(' '));
		speed.erase(speed.find_last_not_of(' ') + 1);

		if (condition == "n" || condition == "N" || condition == "") {
			m_cond = "new";
		}
		else if (condition == "u" || condition == "U") {
			m_cond = "used";
		}
		else if (condition == "b" || condition == "B") {
			m_cond = "broken";
		}
		else {
			throw std::string("Invalid record!");
		}

		try{
			m_speed = std::stod(speed);
		}
		catch (...)
		{
			throw std::string("Invalid record!");
		}
	}

	string Car::condition() const {
		return m_cond;
	}

	double Car::topSpeed() const {
		return m_speed;
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out.width(10);
		out << std::right;
		out << m_make;
		out << " | ";

		out.width(6);
		out << std::left;
		out << m_cond;
		out << " | ";

		out.width(6);
		out << std::right;
		out << std::fixed;
		out << std::setprecision(2);
		out << topSpeed();
		out << " |";

	}

}
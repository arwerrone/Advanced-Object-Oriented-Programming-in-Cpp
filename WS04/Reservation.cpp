#include <iostream>
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds {

	Reservation::Reservation() : m_id{ "" }, m_name{ "" }, m_email{ "" }, m_numOfPeople{ 0 }, m_day{ 0 }, m_hour{ 0 } {}

	Reservation::Reservation(const string& res) {	//Possivel erro
		string temp = res;
		string temp_id, temp_name, temp_email, temp_people, temp_day, temp_hour;

		temp_id = temp.substr(0, temp.find(':'));
		temp.erase(0, temp.find(':') + 1);

		temp_name = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		temp_email = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		temp_people = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		temp_day = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		temp_hour = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);


		temp_id.erase(0, temp_id.find_first_not_of(' '));
		temp_id.erase(temp_id.find_last_not_of(' ') + 1);

		temp_name.erase(0, temp_name.find_first_not_of(' '));
		temp_name.erase(temp_name.find_last_not_of(' ') + 1);

		temp_email.erase(0, temp_email.find_first_not_of(' '));
		temp_email.erase(temp_email.find_last_not_of(' ') + 1);


		m_id = temp_id;
		m_name = temp_name;
		m_email = temp_email;
		m_numOfPeople = stoi(temp_people);
		m_day = stoi(temp_day);
		m_hour = stoi(temp_hour);

	}

	ostream& operator<<(ostream& os, const Reservation& res) {		//ARRUMAR OUTPUT
		os << "Reservation ";
		os.width(10);
		os.setf(ios::right);
		os << res.m_id << ": ";
		os.width(20);
		os.setf(ios::right);
		os << res.m_name << "  ";
		os.unsetf(ios::right);
		os.width(20);
		os.setf(ios::left);
		os << "<" + res.m_email + ">" << "    ";

		if (res.m_hour >= 6 && res.m_hour <= 9) {
			os << "Breakfast";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			os << "Lunch";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << res.m_day << " @ ";
		os << res.m_hour << ":00" << " for ";
		os << res.m_numOfPeople; 
		os << (res.m_numOfPeople == 1 ? " person." : " people.") ;
		os << endl;

		return os;
	}
}
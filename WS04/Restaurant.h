#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* m_reservation{ nullptr };
		size_t m_resNum{0};
		size_t CALL_CNT{0};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(Restaurant&& src) noexcept;
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, Restaurant& right);

	};

}

#endif
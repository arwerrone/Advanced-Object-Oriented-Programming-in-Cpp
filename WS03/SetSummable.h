#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template<int N, typename T>
	class SetSummable: public Set<N,T> {
	public:
		T accumulate(const std::string& filter) const {
			T m_filtered(filter);
			for (size_t i = 0; i < this->size() ; i++) {
				if (m_filtered.isCompatibleWith(this->get(i))) {
					m_filtered += this->get(i);
				}
			}
			return m_filtered;
		}
	};

}

#endif
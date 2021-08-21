#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>

namespace sdds {

	template<int N, typename T>
	class Set {
		T m_arr[N];
		size_t m_currentStorage = 0;
	public:
		size_t size() const {
			return m_currentStorage;
		}
		const T& get(size_t idx) const {
			return m_arr[idx];
		}
		//void operator+=(const T& item);
		void operator+=(const T& item) {
			if (m_currentStorage < N) {
				m_arr[m_currentStorage] = item;
				m_currentStorage++;
			}
		}
	};

}

#endif
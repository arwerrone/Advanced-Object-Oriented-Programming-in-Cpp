#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds {

	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t m_minField;
	public:
		PairSummable(){}
		PairSummable(const K& key, const V& value = initial): Pair<V,K>(key, value) {
			if (m_minField < key.size()) {
				m_minField = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			bool toret = false;
			if (this->key() == b.key()) {
				toret = true;
			}
			return toret;
		}
		PairSummable& operator+=(const PairSummable<V, K>& b) {
			if (this->key() == b.key()) {
				PairSummable opPlusEqual(this->key(), this->value() + b.value());
				*this = opPlusEqual;
			}
			return *this;

		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(m_minField);
			Pair<V, K>::display(os);
			os.setf(std::ios::right);
			os.unsetf(std::ios::right);
		}
	};


	template<typename V, typename K>
	size_t PairSummable<V, K>::m_minField = 0;
	template<> std::string PairSummable<std::string, std::string>::initial = "";
	template<> int PairSummable<int, std::string>::initial = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& b) {
		if (this->key() == b.key()) {
			if (this->value() == "") {
				PairSummable<std::string, std::string> opPlusEqual(this->key(), this->value() + b.value());
				*this = opPlusEqual;
			}
			else {
				PairSummable<std::string, std::string> opPlusEqual(this->key(), this->value() +", "+ b.value());
				*this = opPlusEqual;
			}
		}
		return *this;
	}

}

#endif
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>
#include "bigint.h" 

namespace Dodecahedron {
	Bigint::Bigint() {
		positive = true;
		base = 1000000000;
		skip = 0;
	}

	Bigint::Bigint(long long value) {
		base = 1000000000;
		skip = 0;
		if (value < 0) {
			positive = false;
			value *= -1;
		}
		else
			positive = true;
		while (value) {
			number.push_back((int) (value % base));
			value /= base;
		}
	}

	Bigint::Bigint(std::string stringInteger) {
		int size = stringInteger.length();
		positive = (stringInteger[0] != '-');
		while (true) {
			if (size <= 0) break;
			if (!positive && size <= 1) break;
			
			int length = 0;
			int num = 0;
			int prefix = 1;
			for (int i(size - 1); i >= 0 && i >= size - 9; --i) {
				if (stringInteger[i] < '0' || stringInteger[i] > '9') break;
				num += (stringInteger[i] - '0') * prefix;
				prefix *= 10;
				++length;
			}
			number.push_back(num);
			size -= length;
		}
	}

	Bigint Bigint::operator+(Bigint const &b) const {
		Bigint c = *this;
		c += b;
		return c;
	}

	Bigint &Bigint::operator+=(Bigint const &b) {
		if (!b.positive)
			return *this -= b;
		std::vector<int>::iterator it1 = number.begin();
		std::vector<int>::const_iterator it2 = b.number.begin();
		int sum = 0;
		while (it1 != number.end() || it2 != b.number.end()) {
			if (it1 != number.end())
				sum += *it1;
			else
				number.push_back(0);
			if (it2 != b.number.end()) {
				sum += *it2;
				++it2;
			}
			*it1 = sum % base;
			++it1;
			sum /= base;
		}
		if (sum) number.push_back(1);
		return *this;
	}
				






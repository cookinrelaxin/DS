#ifndef DODECAHEDRON_BIGINT_H_
#define DODECAHEDRON_BIGINT_H_

#include <string>
#include <iostream>
#include <map>

namespace Dodecahedron {
	class Bigint {
		private:
			std::vector<int> number;
			bool positive;
			int base;
			unsigned int skip;
		public:
			Bigint();
			Bigint(long long);
			Bigint(std::string);

			Bigint operator+(Bigint const &) const;
			Bigint &operator+=(Bigint const &);
			Bigint operator+(long long const &) const;
			Bigint &operator+=(long long const &);

			Bigint operator-(Bigint const &) const;
			Bigint &operator-=(Bigint const &);

			Bigint operator*(Bigint const &) const;
			Bigint &operator*=(Bigint const &);
			Bigint operator*(long long const &) const;
			Bigint &operator*=(long long const &);

			Bigint operator/(Bigint const &) const;
			Bigint &operator/=(Bigint const &);
			Bigint operator/(long long const &) const;
			Bigint &operator/=(long long const &);

			bool operator<(const Bigint &) const;
			bool operator>(const Bigint &) const;
			bool operator<=(const Bigint &) const;
			bool operator>=(const Bigint &) const;
			bool operator==(const Bigint &) const;

			Bigint operator=(const long long &);

			int operator[](int const &);

			friend std::istream &operator>>(std::istream &, Bigint &);
			friend std::ostream &operator<<(std::ostream &, Bigint &);

			void clear();
			Bigint &abs();

			Bigint &pow(int const &);

			int digits() const;
			int trailing_zeros() const;
		private:
			int segment_length(int) const;
			Bigint pow(int const &, std::map<int, Bigint> &);
			int compare(Bigint const &) const;
	};

	Bigint abs(Bigint);
	std::string to_string(Bigint);
	Bigint factorial(int);
}

#endif

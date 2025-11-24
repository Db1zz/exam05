#ifndef BIG_INT_HPP_
#define BIG_INT_HPP_

#include <string>
#include <ostream>

class bigint {
public:
	bigint();
	bigint(unsigned long long int num);
	bigint(const std::string& num);
	bigint(const bigint& num);
	bigint& operator=(const bigint& num);

	bigint operator+(const bigint& num) const;
	bigint& operator+=(const bigint& num);
	bigint& operator++();
	bigint operator++(int);

	bool operator<(const bigint& num);
	bool operator<=(const bigint& num);
	bool operator>(const bigint& num);
	bool operator>=(const bigint& num);
	bool operator==(const bigint& num);
	bool operator!=(const bigint& num);

	bigint operator>>(int n);
	bigint operator<<(int n);
	bigint& operator>>=(int n);
	bigint& operator<<=(int n);

	bigint operator>>(const bigint& b);
	bigint operator<<(const bigint& b);
	bigint& operator>>=(const bigint& b);
	bigint& operator<<=(const bigint& b);
	const std::string& get_num();

	friend std::ostream& operator<<(std::ostream& os, const bigint& b);
private:
	std::string add_num(const std::string& a, const std::string& b) const;
	bool is_smaller(const bigint& num);

	std::string _num;
};

#endif // BIG_INT_HPP_
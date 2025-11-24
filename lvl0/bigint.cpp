#include "bigint.hpp"

#include <iostream>

bigint::bigint()
	: _num("0") {}

bigint::bigint(unsigned long long int num) {
	while (num != 0)
	{
		_num.insert(_num.begin(), num % 10 + '0');
		num /= 10;
	}
}

bigint::bigint(const std::string& num)
	: _num(num) {}

bigint::bigint(const bigint& num)  {
	*this = num;
}

bigint& bigint::operator=(const bigint& num) {
	if (this == &num) {
		return *this;
	}

	_num = num._num;
	return *this;
}

bigint bigint::operator+(const bigint& num) const {
	return bigint(add_num(_num, num._num));
}

bigint& bigint::operator+=(const bigint& num) {
	_num = add_num(_num, num._num);
	return *this;
}

bigint& bigint::operator++() {
	std::string one("1");

	_num = add_num(_num, one);
	return *this;
}

bigint bigint::operator++(int) {
	bigint result = *this;
	++(*this);

	return result;
}

bool bigint::operator<(const bigint& num) {
	return _num != num._num && is_smaller(num) == false;
}

bool bigint::operator<=(const bigint& num) {
	return _num == num._num || is_smaller(num) == false;
}

bool bigint::operator>(const bigint& num) {
	return _num != num._num && is_smaller(num) == true;
}

bool bigint::operator>=(const bigint& num) {
		return _num == num._num || is_smaller(num) == true;
}

bool bigint::operator==(const bigint& num) {
	return _num == num._num;
}

bool bigint::operator!=(const bigint& num) {
	return _num != num._num;
}

bigint bigint::operator>>(int n) {
	if (n > _num.size()) {
		return bigint(0);
	}
	return bigint(_num.substr(0, _num.size() - n));
}

bigint bigint::operator<<(int n) {
	std::string num = _num;
	for (int i = 0; i < n; ++i) {
		num.append("0");
	}
	return bigint(num);
}

bigint& bigint::operator>>=(int n) {
	_num = _num.substr(0, _num.size() - n);
	return *this;
}

bigint& bigint::operator<<=(int n) {
	for (int i = 0; i < n; ++i) {
		_num.append("0");
	}
	return *this;
}

bigint bigint::operator>>(const bigint& b) {
	if (b._num.size() > _num.size()) {
		return bigint(0);
	}

	int a = std::atoi(b._num.c_str());
	if (a > _num.size()) {
		return bigint(0);
	}

	return bigint(_num.substr(0, _num.size() - a));
}

bigint bigint::operator<<(const bigint& b) {
	int a = std::atoi(b._num.c_str());

	if (a == 0) {
		return *this;
	}

	std::string num = _num;
	num.insert(num.end() - 1, a, '0');
	return bigint(num);
}

bigint& bigint::operator>>=(const bigint& b) {
	*this = *this >> b;
	return *this;
}

bigint& bigint::operator<<=(const bigint& b) {
	*this = *this << b;
	return *this;
}

std::string bigint::add_num(const std::string& a, const std::string& b) const {
	std::string result;

	const std::string* biggest = &a;
	const std::string* smallest = &b;
	if (biggest->size() < smallest->size()) {
		std::swap(biggest, smallest);
	}

	std::string::const_iterator bg = biggest->end() - 1;
	std::string::const_iterator sm = smallest->end() - 1;

	int carry = 0;
	while (bg >= biggest->begin()) {
		int temp_num = 0;
		if (sm >= smallest->begin()) {
			temp_num += *sm - '0';
			--sm;
		}

		temp_num += *bg - '0' + carry;
		int mod = temp_num % 10;
		carry = (temp_num - mod) / 10;
		result.insert(result.begin(), static_cast<char>(mod + 48));
		--bg;
	}

	if (carry > 0) {
		result.insert(result.begin(), static_cast<char>(carry + 48));
	}

	return result;
}

bool bigint::is_smaller(const bigint& num) {
	if (_num.size() != num._num.size()) {
		return _num.size() > num._num.size();
	}
	int i = 0;

	while (_num[i] == num._num[i] && i < _num.size()) {
		++i;
	}

	if (i == _num.size()) {
		return false;
	}

	return _num[i] > num._num[i];
}

const std::string& bigint::get_num() {
	return _num;
}

std::ostream& operator<<(std::ostream& os, const bigint& b) {
	os << b._num;
	return os;
}
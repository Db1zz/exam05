#include "set.hpp"

set::set(searchable_bag& bag)
	: _bag(bag) {

}

set::set(const set& copy) 
	: _bag(copy._bag) {
}

set& set::operator=(const set& copy) {
	if (this == &copy) {
		return *this;
	}

	_bag = copy._bag;
	return *this;
}

set::~set() {}


void set::insert (int val) {
	_bag.insert(val);
}

void set::insert (int *arr, int size) {
	for (int i = 0; i < size; ++i) {
		_bag.insert(arr[i]);
	}
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

bool set::has(int value) const {
	return _bag.has(value);
}

searchable_bag& set::get_bag() {
	return _bag;
}

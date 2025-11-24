#ifndef SET_HPP_
#define SET_HPP_

#include "searchable_bag.hpp"

class set : public searchable_bag {
public:
	set(searchable_bag& bag);
	set(const set& copy);
	set& operator=(const set& copy);
	~set();

	void insert (int x);
	void insert (int *z, int val);
	void print() const;
	void clear();
	bool has(int) const;
	searchable_bag& get_bag();

private:
	set();

	searchable_bag& _bag;
};

#endif // SET_HPP_
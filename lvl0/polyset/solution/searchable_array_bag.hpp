#ifndef SEARCHABLE_ARRAY_BAG_HPP_
#define SEARCHABLE_ARRAY_BAG_HPP_

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
	bool has(int value) const;
};

#endif // SEARCHABLE_ARRAY_BAG_HPP_
 
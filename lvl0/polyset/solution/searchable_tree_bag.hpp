#ifndef SEARCHABLE_TREE_BAG_HPP_
#define SEARCHABLE_TREE_BAG_HPP_

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
	bool has(int n) const;
private:
	bool has(int n, const tree_bag::node* node) const;
};

#endif // SEARCHABLE_TREE_BAG_HPP_
 
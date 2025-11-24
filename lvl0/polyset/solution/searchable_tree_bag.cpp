#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const {
	return has(n, tree);
}

bool searchable_tree_bag::has(int n, const tree_bag::node* node) const {
	if (node == nullptr) {
		return false;
	}

	if (node->value == n) {
		return true;
	}

	return has(n, node->l) || has(n, node->r);
}
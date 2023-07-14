// Interface & struct definitions for binary_search_tree class.
// Created by Cole Nemec on 7/14/23.

// binary_search_tree is a template class representing a binary search tree of Nodes. Each Node stores data and a pointer to the left/right sub-tree.
	// binary_search_tree's public methods typically call private recursive methods & are
		// binary_search_tree: Constructor
		// ~binary_search_tree: Destructor
		// add(ItemType&): Add data to tree
		// remove(ItemType&): Remove data from tree // TODO should this be keytype?
		// display: Display all data in tree, preserving tree-order
		// get_data(KeyType&): Return data that matches the passed KeyType key
		// height: get height of tree
	// binary_search_tree's private methods are:
		// recursive_destructor: Recursively destroys tree
		// recursive_add: Add data to tree using recursion
		// recursive_remove: Remove data from tree using recursion
		// recursive_display: Display all data in the tree in tree-order, recursively
		// recursive_get_data: Return data that matches the passed KeyType key by navigating to it recursively
		// recursive_height: get height of the tree recursively

#ifndef SOURCE_BINARY_SEARCH_TREE_HH
#define SOURCE_BINARY_SEARCH_TREE_HH

#include "my_exceptions.h"
#include "tree_header.hh"



template<class KeyType, class ItemType>
class binary_search_tree {
private:
	Node<ItemType> * root;

	virtual bool recursive_destructor(Node<ItemType> * & n_);
	virtual bool recursive_add(Node<ItemType> * & n_, ItemType& add_);
	virtual bool recursive_remove(Node<ItemType> * & n_, ItemType& remove_) throw(TargetNotFoundException);
	virtual bool recursive_display(Node<ItemType> * & n_);
	virtual bool recursive_get_data(Node<ItemType> * & n_, KeyType& target_, ItemType * & data_) throw(TargetNotFoundException);
	virtual int recursive_height(Node<ItemType> * & n_);

public:
	binary_search_tree() = 0; // TODO default?
	~binary_search_tree();

	bool add(ItemType& add_);
	bool remove(ItemType& remove_); // TODO should this be keytype?
	bool display();
	bool get_data(KeyType& target_, ItemType * & data_);
	int height();
};


#endif //SOURCE_BINARY_SEARCH_TREE_HH

//
// Created by Cole Nemec on 7/14/23.
//

#ifndef SOURCE_DESTINATION_NAME_TREE_HH
#define SOURCE_DESTINATION_NAME_TREE_HH
#include "binary_search_tree.hh" // will destination_name_tree be able to see binary_search_tree's public methods?

// destination_name_tree is a class representing a binary search tree of Nodes ordered by their Destination's name. Each Node stores Destination data and a pointer to the left/right sub-tree.
// destination_name_tree's public methods typically call private recursive methods & are
// binary_search_tree: Constructor
// ~binary_search_tree: Destructor
// add(Destination&): Add data to tree
// remove(Destination&): Remove data from tree // TODO should this be keytype?
// display: Display all data in tree, preserving tree-order
// get_data(KeyType&): Return data that matches the passed KeyType key
// height: get height of tree
// destination_name_tree's private methods are:
// recursive_destructor: Recursively destroys tree
// recursive_add: Add data to tree using recursion
// recursive_remove: Remove data from tree using recursion
// recursive_display: Display all data in the tree in tree-order, recursively
// recursive_get_data: Return data that matches the passed KeyType key by navigating to it recursively
// recursive_height: get height of the tree recursively

class destination_name_tree   {
private:
	Node<Destination> * root;

	bool recursive_destructor(Node<Destination> * & n_);
	bool recursive_add(Node<Destination> * & n_, Destination& add_);
	bool recursive_remove(Node<Destination> * & n_, Destination& remove_) throw(TargetNotFoundException);
	bool recursive_display(Node<Destination> * & n_);
	bool recursive_get_data(Node<Destination> * & n_, char* & target_, Destination * & data_) throw(TargetNotFoundException);
	int recursive_height(Node<Destination> * & n_);

public:
	destination_name_tree(); // TODO default?
	~destination_name_tree();

	bool add(Destination& add_);
	bool remove(Destination& remove_); // TODO should this be keytype?
	bool display();
	bool get_data(char* & target_, Destination * & data_);
	int height();
};

#endif //SOURCE_DESTINATION_NAME_TREE_HH

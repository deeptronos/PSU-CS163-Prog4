// Carrano & Henry Listing 16-4


#ifndef SOURCE_BINARY_SEARCH_TREE_H
#define SOURCE_BINARY_SEARCH_TREE_H

#include "binary_tree_interface.h"
#include "binary_node.h"
#include "binary_node_tree.h"

#include "my_exceptions.h"

template <class ItemType>
class binary_search_tree : binary_node_tree<ItemType>{
private:
//	binary_node<ItemType> * root_ptr;

protected: // We may wanna just make these private so we don't get points off :P
	//-----------------------------------------------------
	// Recursive methods, to be accessed by public wrappers
	//-----------------------------------------------------
	// Recursively finds where the given node should be placed & inserts it in a leaf at that point.
	binary_node<ItemType> * insertInorder(binary_node<ItemType> * sub_tree_ptr, binary_node<ItemType> * new_node_ptr);

	// Removes the given target value from the tree while maintaining balance of binary search tree.
	binary_node<ItemType> * removeValue(binary_node<ItemType> * sub_tree_ptr, const ItemType target, bool& success);

	// Removes the given target node from a tree while maintaining binary search tree balance.
	binary_node<ItemType> * removeNode(binary_node<ItemType> * node_ptr);

	// Removes the leftmost node of the left subtree pointed to by sub_tree_ptr and
	//  sets inorderSuccessor to the value of that node. Returns a pointer to the revised subtree
	binary_node<ItemType> * removeLeftmostNode(binary_node<ItemType> * sub_tree_ptr, ItemType& inorder_successor);

	// Returns a pointer to the node containing the given value, or nullptr if not found.
	binary_node<ItemType> * findNode(binary_node<ItemType> * tree_ptr, const ItemType& target) const;


public:
	//----------------------------
	// Constructors and Destructor
	//----------------------------
	binary_search_tree();
	binary_search_tree(const ItemType& root_item);
	binary_search_tree(const binary_search_tree<ItemType> & tree);
	virtual ~binary_search_tree();

	//--------------
	//Public Methods
	//--------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData    () const throw(PreconditionViolatedException);
	void setRootData(const ItemType& new_data) const throw(PreconditionViolatedException);
	bool add(const ItemType& new_entry);
	bool remove(const ItemType& an_entry);
	void clear();
	ItemType getEntry(const ItemType& an_entry) const throw(NotFoundException);
	bool contains(const ItemType& an_entry) const;

	//------------------
	// Public Traversals
	//------------------
	void preorderTraversal(void visit(ItemType&)) const;
	void inorderTraversal(void visit(ItemType&)) const;
	void postorderTraversal(void visit(ItemType&)) const;

	//-------------------
	//Overloaded Operator
	//-------------------
	binary_search_tree<ItemType>& operator=(const binary_search_tree<ItemType>& rhs);


};
#include "binary_search_tree.cc"

#endif //SOURCE_BINARY_SEARCH_TREE_H

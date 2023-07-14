/**ADT binary tree: Link-based implementation. @file binary_node_tree.h */

#ifndef SOURCE_BINARY_NODE_TREE_H
#define SOURCE_BINARY_NODE_TREE_H

#include "binary_tree_interface.h"
#include "binary_node.h"
#include "my_exceptions.h"

template<class ItemType>
class binary_node_tree : public binary_tree_interface<ItemType>  {
private:
	binary_node<ItemType> * root_ptr;

protected:
// --------------------------------------------------------
// Protected Utility Methods:
// Recursive helper methods for the public wrapper methods.
// --------------------------------------------------------
	int recursive_getHeight(binary_node<ItemType> * sub_tree_ptr) const;
	int recursive_getNumberOfNodes(binary_node<ItemType> * sub_tree_ptr) const;

	// Recursively deletes all nodes in the tree.
	void recursive_destroyTree(binary_node<ItemType> * sub_tree_ptr);

	// Recursively adds a new node to the tree in a left/right fashion to keep the tree balanced.
	binary_node<ItemType> * recursive_balancedAdd(binary_node<ItemType> * sub_tree_ptr, binary_node<ItemType> * new_node_ptr);

	// Removes target value from the tree by calling recursive_moveValuesUpTree to overwrite value with value from child.
	binary_node<ItemType> * recursive_removeValue(binary_node<ItemType> * sub_tree_ptr, const ItemType target, bool& success);

	// Copies values up the tree to overwrite value in current node until a leaf is reached; the leaf is then removed, since its value is stored in the parent.
	binary_node<ItemType> * recursive_moveValuesUpTree(binary_node<ItemType> * sub_tree_ptr);// TODO is naming correct? implemented recursively?    // TODO not implemented...? unneccessary? // TODO I don't understand the description of this method... I'd implement it otherwise

	// Recursively searches for target value in the tree by using a preorder traversal.
	binary_node<ItemType> * recursive_findNode(binary_node<ItemType> * tree_ptr, const ItemType& target, bool& success) const; // TODO not implemented...? unneccessary?

	// Copies the tree rooted at tree_ptr and returns a pointer to the copy.
	binary_node<ItemType> * copy_tree(const binary_node<ItemType> * tree_ptr) const;

// ----------------------------------
// Recursive Traversal Helper Methods
// ----------------------------------
	void recursive_preorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const;
	void recursive_inorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const;
	void recursive_postorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const;

public:
// ----------------------------------
// Constructor and Destructor Methods
// ----------------------------------
	binary_node_tree();
	binary_node_tree(const ItemType& root_item);
	binary_node_tree(const ItemType& root_item, const binary_node_tree<ItemType> * left_tree_ptr, const binary_node_tree<ItemType> * right_tree_ptr);
	binary_node_tree(const binary_node_tree<ItemType>& tree); // Implicitly uses recursive method (traversal)
	virtual ~binary_node_tree(); // Implicitly uses recursive method (traversal)

// ------------------------------------
// Public binary_tree_interface Methods
// ------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PreconditionViolatedException);
	void setRootData(const ItemType& new_data);
	// Adds a node
	bool add(const ItemType& new_data);
	// Removes a node
	bool remove(const ItemType& data);
	void clear();
	ItemType getEntry(const ItemType& an_entry) const throw(NotFoundException);
	bool contains(const ItemType& an_entry) const;

// ------------------------
// Public Traversal Methods
// ------------------------
	void preorderTraversal(void visit(ItemType&)) const;
	void inorderTraversal(void visit(ItemType&)) const;
	void postorderTraversal(void visit(ItemType&)) const;

// ------------------
// Operator Overloads
// ------------------
	binary_node_tree& operator=(const binary_node_tree& rhs);

};

//#include "binary_node_tree.cc"
#endif //SOURCE_BINARY_NODE_TREE_H


#ifndef SOURCE_BINARY_TREE_INTERFACE_H
#define SOURCE_BINARY_TREE_INTERFACE_H

#include "my_exceptions.h"

template<class ItemType>
class binary_tree_interface { // todo Data??
private:
	virtual void recursive_preorderTraversal(void visit(ItemType&)) const = 0;
	virtual void recursive_inorderTraversal(void visit(ItemType&)) const = 0;
	virtual void recursive_postorderTraversal(void visit(ItemType&)) const = 0;

public:
	virtual bool isEmpty() const            = 0;
	virtual int getHeight() const           = 0;
	virtual int getNumberOfNodes() const    = 0;

	/** Gets the data that is in the root of this binary tree.
	 * @pre The binary tree is not empty.
	 * @post The root’s data has been returned, and the binary tree is unchanged.
	 * @return The data in the root of the binary tree. */
	virtual ItemType getRootData() const    = 0;

	/** Replaces the data item in the root of this binary tree with the given data,
    * if the tree is not empty. However, if the tree is empty, inserts a new
    * root node containing the given data into the tree.
    * @pre None.
    * @post The data in the root of the binary tree is as given.
    * @param newData The data for the root. */
	virtual void setRootData(const ItemType& new_data)  = 0;
	virtual bool add(const ItemType& new_data)          = 0;
	virtual bool remove(const ItemType& data_)          = 0;

	virtual void clear() = 0;

	virtual ItemType getEntry(const ItemType& entry_) const = 0; // throw(TargetNotFoundException) = 0 TOOD use this in body

	virtual bool contains(const ItemType& entry_);

	// Traversals:
	virtual void preorderTraversal(void visit(ItemType&)) const      = 0; // todo implement these recursively?? see ch15    // Wrapper for recursive implementation
	virtual void inorderTraversal(void visit(ItemType&)) const      = 0;
	virtual void postorderTraversal(void visit(ItemType&)) const    = 0;
};


#endif //SOURCE_BINARY_TREE_INTERFACE_H

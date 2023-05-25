
#ifndef SOURCE_BINARY_TREE_INTERFACE_H
#define SOURCE_BINARY_TREE_INTERFACE_H

#include "my_exceptions.h"

template<class ItemType>
class binary_tree_interface {
public:
	virtual bool isEmpty() const            = 0;
	virtual int getHeight() const           = 0;
	virtual int getNumberOfNodes() const    = 0;
	virtual ItemType getRootData() const    = 0;

	virtual void setRootData(const ItemType& new_data)  = 0;
	virtual bool add(const ItemType& new_data)          = 0;
	virtual bool remove(const ItemType& data_)          = 0;

	virtual void clear() = 0;

	virtual ItemType getEntry(const ItemType& entry_) const = 0; // throw(TargetNotFoundException) = 0 TOOD use this in body

	virtual bool contains(const ItemType& entry_);

	// Traversals:
	virtual void preorderTraverse(void visit(ItemType&)) const      = 0;
	virtual void inorderTraversal(void visit(ItemType&)) const      = 0;
	virtual void postorderTraversal(void visit(ItemType&)) const    = 0;
};


#endif //SOURCE_BINARY_TREE_INTERFACE_H


#ifndef SOURCE_BINARY_NODE_H
#define SOURCE_BINARY_NODE_H

template<class ItemType>
class binary_node {
private:
	ItemType item; // Data
	binary_node<ItemType> * left_child_ptr;
	binary_node<ItemType> * right_child_ptr;

public:
	binary_node();
	binary_node(const ItemType& item_);
	binary_node(const ItemType& item_, binary_node<ItemType> * left_ptr, binary_node<ItemType> * right_ptr);

	void setItem(const ItemType& item_); // TODO can we use setter/getter model?
	ItemType getItem() const;

	bool isLeaf() const;

	binary_node<ItemType> * getLeftChildPtr() const;
	binary_node<ItemType> * getRightChildPtr() const;

	void setLeftChildPtr(binary_node<ItemType> * left_ptr);
	void setRightChildPtr(binary_node<ItemType> * right_ptr);
};

//#include "binary_node.cc"

#endif //SOURCE_BINARY_NODE_H

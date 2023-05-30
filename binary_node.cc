
#include "binary_node.h"
#include <cstddef> // use of nullptr causes "undeclared identifier" without cstddef.... this is not the case in any other implementation file??

template <class ItemType>
binary_node<ItemType>::binary_node() : item(nullptr), left_child_ptr(nullptr), right_child_ptr(nullptr){} // default constructor using initializer

template <class ItemType>
binary_node<ItemType>::binary_node(const ItemType &item_) : item(item_), left_child_ptr(nullptr), right_child_ptr(nullptr) {}

template <class ItemType>
binary_node<ItemType>::binary_node(const ItemType &item_, binary_node<ItemType> *left_ptr, binary_node<ItemType> *right_ptr)
	: item(item_), left_child_ptr(left_ptr), right_child_ptr(right_ptr) {}




template <class ItemType>
void binary_node<ItemType>::setItem(const ItemType &item_) {
	item = item_;
}

template <class ItemType>
ItemType binary_node<ItemType>::getItem() const {
	return item;
}

template <class ItemType>
bool binary_node<ItemType>::isLeaf() const {
	return(left_child_ptr == nullptr && right_child_ptr == nullptr);
}

template <class ItemType>
binary_node<ItemType> * binary_node<ItemType>::getLeftChildPtr() const {
	return left_child_ptr;
}

template <class ItemType>
binary_node<ItemType> * binary_node<ItemType>::getRightChildPtr() const {
	return right_child_ptr;
}

template <class ItemType>
void binary_node<ItemType>::setLeftChildPtr(binary_node<ItemType> *left_ptr) {
	left_child_ptr = left_ptr;
}

template <class ItemType>
void binary_node<ItemType>::setRightChildPtr(binary_node<ItemType> *right_ptr) {
	right_child_ptr = right_ptr;
}
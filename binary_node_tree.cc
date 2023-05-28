
#include "binary_node_tree.h"

template<class ItemType>
binary_node_tree<ItemType>::binary_node_tree(): root_ptr(nullptr){ // Uses an initializer to set the value of root_ptr to nullptr.
} // End default constructor

template<class ItemType>
binary_node_tree<ItemType>::binary_node_tree(const ItemType& root_item){
	root_ptr = new binary_node<ItemType>(root_item, nullptr, nullptr);
}

template<class ItemType>
binary_node_tree<ItemType>::binary_node_tree(const ItemType& root_item, const binary_node_tree<ItemType> * left_tree_ptr, const binary_node_tree<ItemType> * right_tree_ptr){
	root_ptr = new binary_node<ItemType>(root_item, copy_tree(left_tree_ptr -> root_ptr), copy_tree(right_tree_ptr -> root_ptr));
}

template<class ItemType>
binary_node_tree<ItemType>::binary_node_tree(const binary_node_tree<ItemType>& tree_ptr){
	root_ptr = copy_tree(tree_ptr.root_ptr);
}

template<class ItemType>
binary_node_tree<ItemType>::~binary_node_tree(){
	recursive_destroyTree(root_ptr);
}



template<class ItemType>
int binary_node_tree<ItemType>::recursive_getHeight(binary_node<ItemType> * sub_tree_ptr) const {
	if(sub_tree_ptr == nullptr){
		return 0;
	}else{
		return 1 + max(recursive_getHeight(sub_tree_ptr->getLeftChildPtr()), recursive_getHeight(sub_tree_ptr->getRightChildPtr()));
	}
}

template<class ItemType>
void binary_node_tree<ItemType>::recursive_destroyTree(binary_node<ItemType> *sub_tree_ptr) {
	if(sub_tree_ptr != nullptr){
		recursive_destroyTree(sub_tree_ptr->getLeftChildPtr());
		recursive_destroyTree(sub_tree_ptr->getRightChildPtr());
		delete sub_tree_ptr;
	}
}

template<class ItemType>
binary_node<ItemType> * binary_node_tree<ItemType>::copy_tree(const binary_node<ItemType> * tree_ptr) const {
	binary_node<ItemType> * new_tree_ptr = nullptr;

	if(tree_ptr != nullptr){ // Copy tree nodes during a preorder traversal
		new_tree_ptr = new binary_node<ItemType>(tree_ptr -> getItem(), nullptr, nullptr);
		new_tree_ptr ->setLeftChildPtr(copy_tree(tree_ptr->getLeftChildPtr()));
		new_tree_ptr ->setRightChildPtr(copy_tree(tree_ptr -> getRightChildPtr()));
	}
	return new_tree_ptr;
}



template<class ItemType>
int binary_node_tree<ItemType>::getHeight() const {
	return recursive_getHeight(root_ptr);
}
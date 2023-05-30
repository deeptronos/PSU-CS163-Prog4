
#include "binary_node_tree.h"

// --------------------------------------------------------
// Protected Utility Methods:
// Recursive helper methods for the public wrapper methods.
// --------------------------------------------------------
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
int binary_node_tree<ItemType>::recursive_getNumberOfNodes(binary_node<ItemType> *sub_tree_ptr) const {
	if(sub_tree_ptr == nullptr){
		return 0;
	}else{
		return(1 + recursive_getNumberOfNodes(sub_tree_ptr -> getLeftChildPtr()) + recursive_getNumberOfNodes(sub_tree_ptr -> getRightChildPtr()));
	}
}

template<class ItemType>
binary_node<ItemType> * binary_node_tree<ItemType>::recursive_balancedAdd(binary_node<ItemType> *sub_tree_ptr, binary_node<ItemType> *new_node_ptr) {
	if(sub_tree_ptr == nullptr){
		return new_node_ptr;
	}else{
		binary_node<ItemType> left_ptr = sub_tree_ptr->getLeftChildPtr();
		binary_node<ItemType> right_ptr = sub_tree_ptr->getRightChildPtr();

		if(recursive_getHeight(left_ptr) > recursive_getHeight(right_ptr)){
			right_ptr = recursive_balancedAdd(right_ptr, new_node_ptr);
			sub_tree_ptr -> setRightChildPtr(right_ptr);
		}else{
			left_ptr = recursive_balancedAdd(left_ptr, new_node_ptr);
			sub_tree_ptr -> setLeftChildPtr(left_ptr);
		}
		return sub_tree_ptr;
	}
}

template<class ItemType>
binary_node<ItemType> * binary_node_tree<ItemType>::recursive_moveValuesUpTree(binary_node<ItemType> *sub_tree_ptr) { // TODO check for leakage/correct destruction...
	if(sub_tree_ptr == nullptr){ // TODO check correctness... TODO is this necessary? Does the else case of the below primary if statement cover this? We'd get an error on the left_ptr, right_ptr declaration lines without this check, right?
		return nullptr;
	}
	binary_node<ItemType> * left_ptr = sub_tree_ptr -> getLeftChildPtr();
	binary_node<ItemType> * right_ptr = sub_tree_ptr -> getRightChildPtr();

	if(left_ptr != nullptr && right_ptr != nullptr){
		if(recursive_getHeight(left_ptr) > recursive_getHeight(right_ptr)){
			sub_tree_ptr -> setItem( left_ptr -> getItem());
			left_ptr = recursive_moveValuesUpTree(left_ptr);
			sub_tree_ptr -> setLeftChildPtr(left_ptr);
			return sub_tree_ptr;

		}else{
			sub_tree_ptr -> setItem( right_ptr -> getItem());
			right_ptr = recursive_moveValuesUpTree(right_ptr);
			sub_tree_ptr -> setRightChildPtr(right_ptr);
			return sub_tree_ptr;

		}
	} // Called on leaf
	return nullptr;

}

template <class ItemType>
binary_node<ItemType> * binary_node_tree<ItemType>::recursive_removeValue(binary_node<ItemType> *sub_tree_ptr,const ItemType target, bool &success) { // TODO check for leakage/correct destruction
	if(sub_tree_ptr == nullptr){
		return nullptr;
	}
	if(sub_tree_ptr -> getItem() == target){
		success = true;
//		sub_tree_ptr = recursive_moveValuesUpTree(sub_tree_ptr);
//		return sub_tree_ptr;
		return(recursive_moveValuesUpTree(sub_tree_ptr)); // TODO equivalent ?
	}
	// Do DFS for target
	binary_node<ItemType> * target_ptr = recursive_removeValue(sub_tree_ptr -> getLeftChildPtr(), target, success);
	sub_tree_ptr -> setLeftChildPtr(target_ptr);
	if(success == false){
		target_ptr = recursive_removeValue(sub_tree_ptr -> getRightChildPtr(), target, success);
		sub_tree_ptr -> setRightChildPtr(target_ptr);
	}
	return sub_tree_ptr;
}
template<class ItemType>
binary_node<ItemType> * binary_node_tree<ItemType>::recursive_findNode(binary_node<ItemType> *tree_ptr, const ItemType &target, bool &success) const {
	if(tree_ptr = nullptr) return nullptr;
	if(tree_ptr -> getItem() == target){
		success = true;
		return tree_ptr;
	}

	binary_node<ItemType> target_ptr = recursive_findNode(tree_ptr -> getLeftChildPtr(), target, success);
	if(success == false) target_ptr = recursive_findNode(tree_ptr -> getRightChildPtr(), target, success);

	return target_ptr;
}



// ----------------------------------
// Recursive Traversal Helper Methods
// ----------------------------------
template<class ItemType>
void binary_node_tree<ItemType>::recursive_preorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const{
	if(tree_ptr != nullptr){
		ItemType the_item = tree_ptr -> getItem();
		visit(the_item);
		recursive_inorder(visit, tree_ptr -> getLeftChildPtr());
		recursive_inorder(visit, tree_ptr -> getRightChildPtr());
	}
}

template<class ItemType>
void binary_node_tree<ItemType>::recursive_inorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const{
	if(tree_ptr != nullptr){
		recursive_inorder(visit, tree_ptr -> getLeftChildPtr());
		ItemType the_item = tree_ptr -> getItem();
		visit(the_item);
		recursive_inorder(visit, tree_ptr -> getRightChildPtr());
	}
};

template<class ItemType>
void binary_node_tree<ItemType>::recursive_postorder(void visit(ItemType&), binary_node<ItemType> * tree_ptr) const{
	if(tree_ptr != nullptr){
		recursive_inorder(visit, tree_ptr -> getLeftChildPtr());
		recursive_inorder(visit, tree_ptr -> getRightChildPtr());
		ItemType the_item = tree_ptr -> getItem();
		visit(the_item);
	}
}


// ----------------------------------
// Constructor and Destructor Methods
// ----------------------------------
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



// ------------------------------------
// Public binary_tree_interface Methods
// ------------------------------------
template<class ItemType>
int binary_node_tree<ItemType>::getHeight() const {
	return recursive_getHeight(root_ptr);
}

template <class ItemType>
int binary_node_tree<ItemType>::getNumberOfNodes() const{
	return recursive_getNumberOfNodes(root_ptr);
};

template<class ItemType>
ItemType binary_node_tree<ItemType>::getRootData() const throw(PreconditionViolatedException) {
	if(isEmpty()){
		throw PreconditionViolatedException();
	}else{
		return(root_ptr->getItem());
	}
}

template<class ItemType>
void binary_node_tree<ItemType>::setRootData(const ItemType &new_data) {
	if(root_ptr == nullptr){
		add(new_data);
	}else{
		root_ptr -> setItem(new_data);
	}
}

template<class ItemType>
bool binary_node_tree<ItemType>::add(const ItemType &new_data) {
	binary_node<ItemType> * new_node_ptr = new binary_node<ItemType>(new_data);
	root_ptr = recursive_balancedAdd(root_ptr, new_node_ptr);

	return true;
}

template <class ItemType>
bool binary_node_tree<ItemType>::isEmpty() const {
	return(root_ptr == nullptr);
}

template <class ItemType>
bool binary_node_tree<ItemType>::remove(const ItemType &data) {
	bool successful = false;

	root_ptr = recursive_removeValue(root_ptr, data, successful);
	return successful;
}

template <class ItemType>
void binary_node_tree<ItemType>::clear() { // TODO check correctness
	recursive_destroyTree(root_ptr);
}

template <class ItemType>
ItemType binary_node_tree<ItemType>::getEntry(const ItemType &an_entry) const throw(NotFoundException) {
	bool successful = false;
	binary_node<ItemType> * node = recursive_findNode(root_ptr, an_entry, successful);

	if(successful == false) return node -> getItem();
	else throw(NotFoundException());

}

template <class ItemType>
bool binary_node_tree<ItemType>::contains(const ItemType &an_entry) const {
	bool successful = false;
	recursive_findNode(root_ptr, an_entry, successful);
	return successful;
}

// ------------------------
// Public Traversal Methods
// ------------------------
template<class ItemType>
void binary_node_tree<ItemType>::preorderTraversal(void (*visit)(ItemType &)) const {
	recursive_preorder(visit, root_ptr);
}

template<class ItemType>
void binary_node_tree<ItemType>::inorderTraversal(void (*visit)(ItemType &)) const {
	recursive_inorder(visit, root_ptr);
}

template<class ItemType>
void binary_node_tree<ItemType>::postorderTraversal(void (*visit)(ItemType &)) const {
	recursive_postorder(visit, root_ptr);
}



// ------------------
// Operator Overloads
// ------------------
template <class ItemType>
binary_node_tree<ItemType>& binary_node_tree<ItemType>::operator=(const binary_node_tree<ItemType> &rhs) {
	if(isEmpty() == false) clear();
	this = copy_tree(&rhs);
	return(* this);
}
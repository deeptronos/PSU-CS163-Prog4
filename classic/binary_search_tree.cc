
#include "binary_search_tree.h"

	//TODO we're just calling all of binary_node_tree's methods... what differentiates this class!??

//-----------------------------------------------------
// Recursive methods, to be accessed by public wrappers
//-----------------------------------------------------
	// TODO none of these are used atm...
template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::insertInorder(binary_node<ItemType> *sub_tree_ptr, binary_node<ItemType> *new_node_ptr) {
	if(sub_tree_ptr == nullptr) return new_node_ptr;
	if((sub_tree_ptr -> getItem()) > new_node_ptr -> getItem()){
		auto temp_ptr = insertInorder(sub_tree_ptr -> getLeftChildPtr(), new_node_ptr);
		sub_tree_ptr -> setLeftChildPtr(temp_ptr);
	}else{
		auto temp_ptr = insertInorder(sub_tree_ptr -> getRightChildPtr(), new_node_ptr);
		sub_tree_ptr ->setRightChildPtr(temp_ptr);
	}
	return sub_tree_ptr;
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::removeValue(binary_node<ItemType> *sub_tree_ptr, const ItemType target, bool &success) {
	if(sub_tree_ptr == nullptr){
		success = false;
		return nullptr;
	}
	if(sub_tree_ptr -> getItem() == target){ // Item in root of some subtree
		sub_tree_ptr = removeNode(sub_tree_ptr);
		success = true;
		return sub_tree_ptr;

	}else if(sub_tree_ptr -> getItem() > target){ // Search left subtree
		binary_node<ItemType> * temp_ptr = removeValue(sub_tree_ptr -> getLeftChildPtr(), target, success);
		sub_tree_ptr -> setLeftChildPtr(temp_ptr);
		return sub_tree_ptr;

	}else{ // Search right subtree
		binary_node<ItemType> * temp_ptr = removeValue(sub_tree_ptr -> getRightChildPtr(), target, success);
		sub_tree_ptr ->setRightChildPtr(temp_ptr);
		return sub_tree_ptr;
	}
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::removeNode(binary_node<ItemType> *node_ptr) {
	if(node_ptr->isLeaf()){
		delete node_ptr;
		node_ptr = nullptr;
		return node_ptr;
	}
	else if((node_ptr -> getLeftChildPtr() == nullptr) != (node_ptr -> getRightChildPtr() == nullptr)){ // node_ptr has only one child
		binary_node<ItemType> * node_to_connect_ptr = nullptr;
		if(node_ptr -> getLeftChildPtr() != nullptr){
			node_to_connect_ptr = node_ptr -> getLeftChildPtr();
		}else{
			node_to_connect_ptr = node_ptr -> getRightChildPtr();
		}
		delete node_ptr;
		node_ptr = nullptr;
		return node_to_connect_ptr;
	}
	else{
		ItemType new_node_value;
		auto temp_ptr = removeLeftmostNode(node_ptr->getRightChildPtr(), new_node_value);
		node_ptr -> setRightChildPtr(temp_ptr);
		node_ptr -> setItem(new_node_value);
		return node_ptr;
	}
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::findNode(binary_node<ItemType> * tree_ptr, const ItemType& target) const{
	if(tree_ptr == nullptr) return nullptr;
	else if(tree_ptr -> getItem() == target) return tree_ptr;
	else if(tree_ptr -> getItem() > target) return findNode(tree_ptr -> getLeftChildPtr(), target);
	else return findNode(tree_ptr -> getRightChildPtr(), target);
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::removeLeftmostNode(binary_node<ItemType> *sub_tree_ptr, ItemType &inorder_successor) {
	if(sub_tree_ptr -> getLeftChildPtr() == nullptr){
		inorder_successor = sub_tree_ptr -> getItem();
		return removeNode(sub_tree_ptr);
	}else return removeLeftmostNode(sub_tree_ptr -> getLeftChildPtr(), inorder_successor);
}



//----------------------------
// Constructors and Destructor
//----------------------------
template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(){ // Should auto-magically call base class (binary_node_tree) default?
}



template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(const ItemType &root_item) : binary_node_tree<ItemType>(root_item){ // TODO check
}


template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(const binary_search_tree<ItemType> &tree) : binary_node_tree<ItemType>(tree){ // TODO check?
}

template<class ItemType>
binary_search_tree<ItemType>::~binary_search_tree(){ // todo Calls base class destructor? (so, recursive_destroyTree(root_ptr)?)
}



//--------------
//Public Methods
//--------------

template <class ItemType>
bool binary_search_tree<ItemType>::add(const ItemType &new_entry) { //TODO is calling these methods with the same name necessary? Could the compiler just understand to use binary_node_tree's methods since its base class?
	return binary_node_tree<ItemType>::add(new_entry);
}

template <class ItemType>
bool binary_search_tree<ItemType>::remove(const ItemType& an_entry){
	return binary_node_tree<ItemType>::remove(an_entry);
}

template <class ItemType>
bool binary_search_tree<ItemType>::isEmpty() const {
	return binary_node_tree<ItemType>::isEmpty();
}

template <class ItemType>
int binary_search_tree<ItemType>::getHeight() const {
	return binary_node_tree<ItemType>::getHeight();
}

template <class ItemType>
int binary_search_tree<ItemType>::getNumberOfNodes() const {
	return binary_node_tree<ItemType>::getNumberOfNodes();
}

template <class ItemType>
ItemType binary_search_tree<ItemType>::getRootData() const throw(PreconditionViolatedException) {
	return binary_node_tree<ItemType>::getRootData();
}

template <class ItemType>
void binary_search_tree<ItemType>::setRootData(const ItemType &new_data) const throw(PreconditionViolatedException) {
	binary_node_tree<ItemType>::setRootData(new_data);
}

template <class ItemType>
void binary_search_tree<ItemType>::clear() { // TODO check correctness
	binary_node_tree<ItemType>::clear();
}

template <class ItemType>
ItemType binary_search_tree<ItemType>::getEntry(const ItemType &an_entry) const throw(NotFoundException) {
	return binary_node_tree<ItemType>::getEntry(an_entry);
}

template <class ItemType>
bool binary_search_tree<ItemType>::contains(const ItemType &an_entry) const {
	return binary_node_tree<ItemType>::contains(an_entry);
}



//------------------
// Public Traversals
//------------------
template <class ItemType>
void binary_search_tree<ItemType>::preorderTraversal(void (*visit)(ItemType &)) const {
	binary_node_tree<ItemType>::preorderTraversal(visit);
}

template <class ItemType>
void binary_search_tree<ItemType>::inorderTraversal(void (*visit)(ItemType &)) const {
	binary_node_tree<ItemType>::inorderTraversal(visit);
}

template <class ItemType>
void binary_search_tree<ItemType>::postorderTraversal(void (*visit)(ItemType &)) const {
	binary_node_tree<ItemType>::postorderTraversal(visit);
}



//-------------------
//Overloaded Operator
//-------------------
//template <class ItemType>
//binary_search_tree<ItemType>& binary_search_tree<ItemType>::operator=(const binary_search_tree<ItemType>& rhs){
//	if(isEmpty() == false) clear();
////	this = this -> copy_tree();
//	this = rhs -> copy_tree();
//	return(* this);
//}
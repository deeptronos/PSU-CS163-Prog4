
#include "binary_search_tree.h"

//-----------------------------------------------------
// Recursive methods, to be accessed by public wrappers
//-----------------------------------------------------
template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::insertInorder(binary_node<ItemType> *sub_tree_ptr, binary_node<ItemType> *new_node_ptr) {
	if(sub_tree_ptr == nullptr) return new_node_ptr;
	if((sub_tree_ptr -> getItem()) > new_node_ptr -> getItem()){
		auto temp_ptr = insertInorder(sub_tree_ptr -> getLeftChildPtr(), new_node_ptr);
		sub_tree_ptr -> setLeftChildPtr(temp_ptr);
	}else{
		auto temp_ptr = insertInorder(sub_tree_ptr -> getRightChildPtr(), new_node_ptr);
		sub_tree_ptr ->setRightChildPtr();
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
	int childcount = 0;
	if(node_ptr -> getRightChildPtr() != nullptr) ++childcount;
	if(node_ptr -> getLeftChildPtr() != nullptr) ++ childcount;

	if(childcount == 1){ // 1 child
		binary_node<ItemType> * node_to_connect_ptr;
		if(node_ptr -> getLeftChildPtr() != nullptr) node_to_connect_ptr = node_ptr -> getLeftChildPtr();
		else node_to_connect_ptr = node_ptr -> getRightChildPtr();

		delete node_ptr;
		node_ptr = nullptr;
		return node_to_connect_ptr;

	}else{ // 2 children
		ItemType * new_node_value;
		binary_node<ItemType> * temp = removeLeftmostNode(node_ptr -> getRightChildPtr(), new_node_value);
		node_ptr -> setItem(new_node_value);
		return node_ptr;
	}
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::findNode(binary_node<ItemType> * tree_ptr, const ItemType& target) const{
	if(tree_ptr == nullptr) return nullptr;
	else if(tree_ptr -> getItem() == target) return tree_ptr;
	else if(tree_ptr -> getItem() > target) return findNode(tree_ptr -> getLeftChildPtr(), target);
	else return findNode(tree_ptr -> getRightChildPtr());
}

template <class ItemType>
binary_node<ItemType> * binary_search_tree<ItemType>::removeLeftmostNode(binary_node<ItemType> *sub_tree_ptr, ItemType &inorder_successor) {
	if(sub_tree_ptr -> getLeftChildPtr() == nullptr){
		inorder_successor == sub_tree_ptr -> getItem();
		return removeNode(sub_tree_ptr);
	}else return removeLeftmostNode(sub_tree_ptr -> getLeftChildPtr(), inorder_successor);
}



//----------------------------
// Constructors and Destructor
//----------------------------
template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(): root_ptr(nullptr)  {} // uses an initializer to set root_ptr to nullptr // TODO check

template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(const ItemType &root_item): root_ptr(new binary_node<ItemType>(root_item, nullptr, nullptr)) { // TODO check
}

template <class ItemType>
binary_search_tree<ItemType>::binary_search_tree(const binary_search_tree<ItemType> &tree) {
	root_ptr = this ->copy_tree(tree.root_ptr);
}

template<class ItemType>
binary_search_tree<ItemType>::~binary_search_tree(){
	this ->recursive_destroyTree(root_ptr);
}



//--------------
//Public Methods
//--------------
template <class ItemType>
bool binary_search_tree<ItemType>::add(const ItemType &new_entry) {
	binary_node<ItemType> * new_node_ptr = new binary_node<ItemType>(new_entry);
	root_ptr = insertInorder(root_ptr, new_node_ptr);
}

template <class ItemType>
bool binary_search_tree<ItemType>::remove(const ItemType& an_entry){
	bool success = false;
	root_ptr = removeValue(root_ptr, an_entry, success);
	return success;
}

template <class ItemType>
bool binary_search_tree<ItemType>::isEmpty() const {
	return(root_ptr == nullptr);
}

template <class ItemType>
int binary_search_tree<ItemType>::getHeight() const {
//	return recursive_getHeight()
	return(this->recursive_getHeight(root_ptr));
}

template <class ItemType>
int binary_search_tree<ItemType>::getNumberOfNodes() const {
	return(this ->recursive_getNumberOfNodes(root_ptr));
}

template <class ItemType>
ItemType binary_search_tree<ItemType>::getRootData() const throw(PreconditionViolatedException) {
	if(this -> isEmpty()) throw PreconditionViolatedException();
	else return(root_ptr -> getItem());
}

template <class ItemType>
void binary_search_tree<ItemType>::setRootData(const ItemType &new_data) const throw(PreconditionViolatedException) {
	if(isEmpty()) add(new_data);
	else root_ptr -> setItem(new_data);
}

template <class ItemType>
void binary_search_tree<ItemType>::clear() { // TODO check correctness
	this ->recursive_destroyTree(root_ptr);
}

template <class ItemType>
ItemType binary_search_tree<ItemType>::getEntry(const ItemType &an_entry) const throw(NotFoundException) {
	bool successful = false;
	binary_node<ItemType> * node = findNode(root_ptr, an_entry, successful);

	if(successful == false) return node -> getItem();
	else throw NotFoundException();
}

template <class ItemType>
bool binary_search_tree<ItemType>::contains(const ItemType &an_entry) const {
	bool successful = false;
	this -> recursive_findNode(root_ptr, an_entry, successful);
	return successful;
}



//------------------
// Public Traversals
//------------------
template <class ItemType>
void binary_search_tree<ItemType>::preorderTraversal(void (*visit)(ItemType &)) const {
	this ->recursive_preorder(visit, root_ptr);
}

template <class ItemType>
void binary_search_tree<ItemType>::inorderTraversal(void (*visit)(ItemType &)) const {
	this ->recursive_inorder(visit, root_ptr);
}

template <class ItemType>
void binary_search_tree<ItemType>::postorderTraversal(void (*visit)(ItemType &)) const {
	this ->recursive_postorder(visit, root_ptr);
}



//-------------------
//Overloaded Operator
//-------------------
template <class ItemType>
binary_search_tree<ItemType>& binary_search_tree<ItemType>::operator=(const binary_search_tree<ItemType>& rhs){
	if(isEmpty() == false) clear();
	this = this -> copy_tree();
	return(* this);
}
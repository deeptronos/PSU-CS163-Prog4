
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
		root_ptr->setItem(new_data);
	}
}

template<class ItemType>
bool binary_node_tree<ItemType>::add(const ItemType &new_data) {
	binary_node<ItemType> * new_node_ptr = new binary_node<ItemType>(new_data);
	root_ptr = recursive_balancedAdd(root_ptr, new_node_ptr);

	return true;
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
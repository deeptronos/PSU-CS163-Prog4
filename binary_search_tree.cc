//
// Created by Cole Nemec on 7/14/23.
//

#include "binary_search_tree.hh"

// ---------------
// Private Methods
// ---------------

template<class KeyType, class ItemType>
bool binary_search_tree<KeyType, ItemType>::recursive_destructor(Node<ItemType> *&n_) {
	if(n_){
		recursive_destructor(n_->left);
		recursive_destructor(n_->right);
		delete n_;
	}
}



// --------------
// Public Methods
// --------------

template<class KeyType, class ItemType>
binary_search_tree<KeyType, ItemType>::~binary_search_tree(){
	recursive_destructor(root);
}

template<class KeyType, class ItemType>
bool binary_search_tree<KeyType, ItemType>::add(ItemType& add_){
	return recursive_add(root, add_);
}

template<class KeyType, class ItemType>
bool binary_search_tree<KeyType, ItemType>::remove(ItemType& remove_){
	try{
		recursive_remove(root, remove_);
		return true;
	}catch(TargetNotFoundException e){
		cout << e.what() << endl;
		return false;
	}
}

template<class KeyType, class ItemType>
bool binary_search_tree<KeyType, ItemType>::display(){
	return recursive_display(root);
}

template<class KeyType, class ItemType>
bool binary_search_tree<KeyType, ItemType>::get_data(KeyType &target_, ItemType *&data_) {
	try{
		recursive_get_data(root, target_, data_);
		return true;
	}catch(TargetNotFoundException e){
		cout << e.what() << endl;
		return false;
	}
}

template<class KeyType, class ItemType>
int binary_search_tree<KeyType, ItemType>::height(){
	return recursive_height(root);
}

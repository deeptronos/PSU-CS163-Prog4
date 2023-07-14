//
// Created by Cole Nemec on 7/14/23.
//

#include "destination_name_tree.hh"


// ---------------
// Private Methods
// ---------------

bool destination_name_tree::recursive_destructor(Node<Destination> *&n_) {
	if(n_){
		recursive_destructor(n_->left);
		recursive_destructor(n_->right);
		delete n_;
	}
}



// --------------
// Public Methods
// --------------


destination_name_tree::~destination_name_tree(){
	recursive_destructor(root);
}

bool destination_name_tree::add(Destination& add_){
	return recursive_add(root, add_);
}

bool destination_name_tree::remove(Destination& remove_){
	try{
		recursive_remove(root, remove_);
		return true;
	}catch(TargetNotFoundException e){
		cout << e.what() << endl;
		return false;
	}
}

bool destination_name_tree::display(){
	return recursive_display(root);
}


bool destination_name_tree::get_data(char* &target_, Destination *&data_) {
	try{
		recursive_get_data(root, target_, data_);
		return true;
	}catch(TargetNotFoundException e){
		cout << e.what() << endl;
		return false;
	}
}

int destination_name_tree::height(){
	return recursive_height(root);
}

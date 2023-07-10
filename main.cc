
#include <cstring> // TODO for what?

#include "testing_interface_bst.h"


using key_t = int;
using item_t = destination;

// Next time: Fix the compilation error where table() is not defined -_-


int main(){
	table<key_t, item_t>* t = new table<key_t, item_t>;
	t->display();

	testing_interface_bst t_i_bst;
	bool run = true;
	do{
		run = t_i_bst.prompt_user();
	}while(run);

	return 0;
}

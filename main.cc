
#include <cstring> // TODO for what?

#include "testing_interface_bst.h"


using key_t = int;
using item_t = destination;

// Next time: figure out how to use the classes youve been working on :P


int main(){
	testing_interface_bst t_i_bst;
	bool run = true;
	do{
		run = t_i_bst.prompt_user();
	}while(run);

	return 0;
}

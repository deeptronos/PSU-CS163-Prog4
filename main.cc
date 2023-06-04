
#include <cstring>

#include "my_exceptions.h"
#include "table.h"
#include "destination.h"


using key_t = int;
using item_t = destination;

void my_visit(tree_entry<key_t, item_t>& i_){
	std::cout << i_.getItem();
}

// Next time: figure out how to use the classes youve been working on :P

int main(){ // testing table with manual key-setting
//	table<char *, tree_entry<key_t, destination> > tbl;
//	tbl = table<key_t, tree_entry<key_t, destination> >();
//	table<key_t, tree_entry<key_t, destination> > tbl; // TODO theo advice: use "template" keyword here ?
//	tbl.add(1, tree_entry<key_t, destination>(1, destination()));

//	table<key_t, tree_entry<key_t, char> > tbl;

	binary_node<int * > bn;

//	binary_search_tree<tree_entry<key_t, item_t> > bst;
//	bst.add(tree_entry<key_t, item_t>('a', 1));

	binary_search_tree<tree_entry<key_t, item_t> > d_bst;

	int ttd_1_size = 3;
	char ** ttd_1 = new char*[ttd_1_size];
	ttd_1[0] = new char[8];
//	strncpy(ttd_1[0], "Surfing", 8);
	strcpy(ttd_1[0], "Surfing");
	ttd_1[1] = new char[16];
//	strncpy(ttd_1[1], "Whale-watching", 16);
	strcpy(ttd_1[1], "Whale-watching");
	ttd_1[2] = new char[23];
//	strncpy(ttd_1[2], "Sunday morning market", 23);
	strcpy(ttd_1[2], "Sunday morning market");
	d_bst.add(tree_entry<key_t, item_t>(destination("Santa Clarita", "CA", "Spring", "Train", ttd_1, ttd_1_size, 8), 1));
	d_bst.inorderTraversal(my_visit); // TODO this segfaults because the nullptr we passed when adding an entry to d_bst
//	throw TargetNotFoundException(); // Todo Doesn't compile.....

}

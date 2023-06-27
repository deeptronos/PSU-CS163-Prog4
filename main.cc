
#include <cstring>

#include "testing_interface_bst.h"


using key_t = int;
using item_t = destination;

void my_visit(tree_entry<key_t, item_t>& i_){
	std::cout << i_.getItem();
}

// Next time: figure out how to use the classes youve been working on :P

int test_bst(){
	binary_node<int * > bn;


	binary_search_tree<tree_entry<key_t, item_t> > d_bst;

//	int ttd_1_size = 3;
//	char ** ttd_1 = new char*[ttd_1_size];
//	ttd_1[0] = new char[8];
//	strcpy(ttd_1[0], "Surfing");
//	ttd_1[1] = new char[16];
//	strcpy(ttd_1[1], "Whale-watching");
//	ttd_1[2] = new char[23];
//	strcpy(ttd_1[2], "Sunday morning market");
	int ttd_1_size = 3;
	const char * ttd_1[] = {"Surfing", "Whale-watching", "Sunday morning market"};

	d_bst.add(tree_entry<key_t, item_t>(destination("Santa Clarita", "CA", "Spring", "Train", ttd_1, ttd_1_size, 8), 1));

//	int ttd_2_size = 2;
//	char ** ttd_2 = new char*[ttd_2_size];
//	ttd_2[0] = new char[30];
//	strcpy(ttd_2[0], "Getting fucked up at a winery");
//	ttd_2[1] = new char[10];
//	strcpy(ttd_2[1], "Skydiving");
	int ttd_2_size = 2;
	const char * ttd_2[] = {"Getting fucked up at a winery", "Skydiving"};
	d_bst.add(tree_entry<key_t, item_t>(destination("Fresno", "CA", "Summer", "Plane", ttd_2, ttd_2_size, 5),2));

	d_bst.inorderTraversal(my_visit);

	return 0;
}

int main(){ // testing table with manual key-setting
//	test_bst();
	table<key_t, item_t> tbl;

	int ttd_1_size = 3;
	const char * ttd_1[] = {"Surfing", "Whale-watching", "Sunday morning market"};
	tbl.add(1,destination("Santa Clarita", "CA", "Spring", "Train", ttd_1, ttd_1_size, 8) );
//	throw TargetNotFoundException(); // Todo Doesn't compile.....

	tbl.traverse(my_visit);
	tbl.display();
	return 0;
}

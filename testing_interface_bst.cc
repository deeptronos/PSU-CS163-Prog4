#include <iostream>

#include "testing_interface_bst.h"
// -------------
// Helper method
// -------------
item_t createDestinationPrompt(int i_size){ // TODO organization?
	int ttd_1_size = 3;
	char * ttd_1[] = {"Surfing", "Whale-watching", "Sunday morning market"};
	tbl.add(1,destination("Santa Clarita", "CA", "Spring", "Train", ttd_1, ttd_1_size, 8) );



	char location_name[i_size];
	char nationstate_identifier[i_size];
	char best_time_of_year[i_size];
	char how_to_get_there[i_size];
//	char things_to_do[i_size/8][i_size]; // Let's not go crazy :P
	char ** things_to_do;

	char things_to_do_size_str[i_size];
	int things_to_do_size;
	char natural_beauty_index_str[i_size];
	int natural_beauty_index;

	cout << "Create a Destination." << endl;
	cout << "Name of the destination:" << endl;
	cin.get(location_name, i_size);

	cout << "Name/abbreviation of the geographic region of the destination (State, Country, Province, etc.)" << endl;
	cin.get(nationstate_identifier, i_size);

	cout << "What's the best season to visit?" << endl;
	cin.get(best_time_of_year, i_size);

	cout << "Best way to get there:" << endl;
	cin.get(how_to_get_there, i_size);

	// Initialize two-dimensional dynamic char array things_to_do
	cout << "Now, tell me about the activities you want to do there.\n Provide the number of activities:" << endl;
	cin.get(things_to_do_size_str, i_size);
	things_to_do_size = strtol(things_to_do_size_str, nullptr, 10);

	things_to_do = new char*[things_to_do_size];

	for(int i = 0; i < things_to_do_size; ++i){ // TODO should we use new char[] for each thing_to_do?
		char thing_to_do[i_size];
		cout << "Activity: " << endl;
		cin.get(thing_to_do, i_size);
		things_to_do[i] = thing_to_do;
	}

	cout << "Rate the natural beauty of this destination on a scale of 1-10:" << endl;
	cin.get(natural_beauty_index_str, i_size);
	natural_beauty_index = strtol(natural_beauty_index_str, nullptr, 10);

	return destination(location_name, nationstate_identifier, best_time_of_year, how_to_get_there, things_to_do, things_to_do_size, natural_beauty_index_str);
}


// -------------
// Public method
// -------------
bool testing_interface_bst::prompt_user() {
	const int i_size = 256; // Allowed size of any char input

	cout << endl; // Whitespace before prompt
	char input;
	cout << "Choose an action:" << endl;
	cout << "1. Initialize a table\n" //TODO: change language to use "tree" instead of "table?
			"2. Add to the table\n"
			"3. Remove from the table\n"
			"4. Display the contents of the table sorted by location name\n"
			"5. Display the contents of the table sorted by location's natural beauty\n"
			"6. Get an item from the table\n"
			"7. Get the height of the table's tree\n"
	        "(Q to quit)" << endl;
	cout << "Input 1-7 or (Q)uit: ";
	cin >> input;
	cin.ignore(100, '\n');

	if(input == '1'){
		table_create();
	}else if (input == '2'){
		char search_key[i_size];
		char new_item[i_size];

		cout << "<CTEST- search_key >Provide a name for the Location:" <<endl;
		cin.get(search_key, i_size); // TODO good practice for input?


	}

}

// --------------------------
// Private non-wrapper method
// --------------------------
bool testing_interface_bst::table_create(){
	if(table_ == nullptr){
		table_ = new table<key_t, item_t>;
		return true;
	}else return false;
}

// ----------------------------------
// Private wrappers for table methods
// ----------------------------------

bool testing_interface_bst::table_add(const key_t& search_key, const item_t& new_item) {
	if(table_){
		table_->add(search_key, new_item);
		return true;
	}else return false;
}

bool testing_interface_bst::table_remove(const key_t& search_key) {
	if(table_){
		table_->remove(search_key);
		return true;
	}else return false;
}

bool testing_interface_bst::table_displayByLocationName() const {
	if(table_){
		table_->displayAll_byLocation();
		return true;
	}else return false;
}

bool testing_interface_bst::table_displayByNaturalBeauty() const {
	if(table_){
		table_->displayAll_byNaturalBeauty();
		return true;
	}else return false;
}

bool testing_interface_bst::table_getItem(const key_t &search_key) const {
	if(table_){
		try{
			table_->getItem(search_key); // TODO what to do with the returned info of this call...
			return true;
		}catch (NotFoundException e){
			cout << e.what() << endl;
			return false;
		}
	}else return false;
}

bool testing_interface_bst::table_getHeight() const {
	if(table_){
		cout << "Tree height: " << table_->getHeight() << endl;
		return true;
	}else return false;

}
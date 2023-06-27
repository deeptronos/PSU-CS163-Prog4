
#ifndef SOURCE_TESTING_INTERFACE_BST_H
#define SOURCE_TESTING_INTERFACE_BST_H

#include "my_exceptions.h"
#include "table.h"
//#include "table.cc"
#include "destination.h"


using key_t = int;
using item_t = destination;

class testing_interface_bst {
public:
	// ----------------------
	// Constructor/Destructor
	// ----------------------

	testing_interface_bst() = default; // TODO
	~testing_interface_bst() = default; // TODO


	// -------------
	// Public method
	// -------------

	// Prompts user for for input to call table methods.
	// Returns true on any input indicating table methods, false when user indicates they want to quit the program.
	bool prompt_user();

private:

	// ----------------------------------
	// Private wrappers for table methods
	// ----------------------------------

	// Create a new table_item
	bool table_create();
	// Add a new location to the table
	bool table_add(const key_t& search_key, const item_t& new_item);
	// Remove by a location name <search_key>
	bool table_remove(const key_t& search_key);
	// Display all in sorted order by location name
	bool table_displayByLocationName() const;
	// Display all in sorted order by natural beauty
	bool table_displayByNaturalBeauty() const; // TODO custom characteristic... to be finalized
	// Retrieve the information for a given Location (this is not display)
	bool table_getItem(const key_t& search_key) const; // TODO should this display info? or return item_t data?
	// Determine the height of the tree (used to assist in evaluating the performance of your software)
	bool table_getHeight() const;

	// ----
	// Data
	// ----
	table<key_t, item_t> * table_;

};


#endif //SOURCE_TESTING_INTERFACE_BST_H

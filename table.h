// Carrano & Henry Listing 18-4

#ifndef SOURCE_TABLE_H
#define SOURCE_TABLE_H

#include "table_interface.h"
#include "binary_search_tree.h"
#include "tree_entry.h"
#include "my_exceptions.h"

template <class KeyType, class ItemType>
class table: public table_interface<KeyType, ItemType> {
private:
	binary_search_tree< tree_entry<KeyType, ItemType> > item_tree;

	void traversalHelper( tree_entry<KeyType, ItemType>& the_entry );

public:
	table();
//	table(int max_number_of_entries); // linear link-based DS, so irrelevant? No "maximum" storage capacity...
	table(const table<KeyType, ItemType>& table_);
	virtual ~table();

	bool isEmpty() const;
	int getNumberOfItems() const;
	int getHeight() const;

	bool add(const KeyType& search_key, const ItemType& new_item);
	bool remove(const KeyType& search_key);

	void clear();
	ItemType getItem(const KeyType& search_key) const throw(NotFoundException);
	bool contains(const KeyType& search_key) const;

	// Display all in sorted order by the Destination's name
	void displayAll_byLocation() const;
	// Display all in sorted order by the Destination's natural beauty index
	void displayAll_byNaturalBeauty() const;


	//Traverses the items in this table in sorted search-key order and calls
	// a given client function once on each item.
	void traverse(void visit(ItemType&)) const;
};


#include "table.cc"

#endif //SOURCE_TABLE_H

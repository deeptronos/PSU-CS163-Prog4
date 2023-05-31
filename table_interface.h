// Carrano & Henry Listing 18-1

#ifndef SOURCE_TABLE_INTERFACE_H
#define SOURCE_TABLE_INTERFACE_H

#include "my_exceptions.h"

template<class KeyType, class ItemType> // Allows data type of table's data entries to differ from the data type of their search keys
class table_interface { // todo data..?
public:
	/**Checks whether this table is empty.
	* @return True if the table is empty; otherwise returns false. */
	virtual bool isEmpty() const = 0;

	/**Gets the number of items in this table.
	* @return The number of items in the table.*/
	virtual int getNumberOfItems() const = 0;

	/**Inserts an item into this table according to the item’s search key.
	* @pre The search key of the new item differs from all search keys presently in the table.
	* @post If the insertion is successful, newItem is in its proper position within the table.
	* @param searchKey The search key associated with the item to be inserted.
	* @param newItem The item to add to the table.
	* @return True if item was successfully added, or false if not. */
	virtual bool add(const KeyType& search_key, const ItemType& new_item) = 0;

	/**Removes an item with the given search key from this table.
	* @post If the item whose search key equals searchKey existed in the table, the item was removed.
	* @param searchKey The search key of the item to be removed.
	* @return True if the item was successfully removed, or false if not. */
	virtual bool remove(const KeyType& search_key) = 0;

	/**Removes all entries from this table. */
	virtual void clear() = 0;

	/**Retrieves an item with a given search key from a table.
	* @post If the retrieval is successful, the item is returned.
	* @param searchKey The search key of the item to be retrieved.
	* @return The item associated with the search key.
	* @throw NotFoundException if the item does not exist. */
	virtual ItemType getItem(const KeyType& search_key) const throw(NotFoundException) = 0;

	/**Sees whether this table contains an item with a given search key.
	* @post The table is unchanged.
	* @param searchKey The search key of the item to be retrieved.
	* @return True if an item with the given search key exists in the table. */
	virtual bool contains(const KeyType& search_key) const = 0;

	/**Traverses this table and calls a given client function once for each item.
	* @post The given function’s action occurs once for each item in the table and possibly alters the item.
	* @param visit A client function. */
	virtual void traverse(void visit(ItemType&)) const = 0;
};


#endif //SOURCE_TABLE_INTERFACE_H

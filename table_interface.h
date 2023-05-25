
#ifndef SOURCE_TABLE_INTERFACE_H
#define SOURCE_TABLE_INTERFACE_H

#include "my_exceptions.h"

template<class KeyType, class ItemType> // Allows data type of table's data entries to differ from the data type of their search keys
class table_interface { // todo data..?
public:
	virtual bool isEmpty() const = 0;

	virtual int getNumberOfItems() const = 0;

	virtual bool add(const KeyType& search_key, const ItemType& new_item) = 0;

	virtual bool remove(const KeyType& search_key) = 0;

	virtual void clear() = 0;

	virtual ItemType getItem(const KeyType& search_key) const throw(NotFoundException) = 0;

	virtual bool contains(const KeyType& search_key) const = 0;

	virtual void traverse(void visit(ItemType&)) const = 0;
};


#endif //SOURCE_TABLE_INTERFACE_H

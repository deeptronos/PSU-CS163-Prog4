// Carrano & Henry Listing 18-2

#ifndef SOURCE_TREE_ENTRY_H
#define SOURCE_TREE_ENTRY_H

class SearchKey{ // TODO should this just be a part of tree_entry?

};

template <class KeyType, class ItemType>
class tree_entry {
private:
	ItemType item;
	KeyType searchKey;
protected:
	void setKey(const KeyType& sk); // Protected to prevent calling outside of member functions

public:
	tree_entry();
//	tree_entry(KeyType search_key, ItemType new_item);
	tree_entry( ItemType new_entry, KeyType search_key);
	~tree_entry();
	ItemType getItem() const;
	KeyType getKey() const;
	void setItem(const ItemType& newEntry);

	void display() const;

	bool operator==(const tree_entry<KeyType, ItemType>& rhs) const;
	bool operator>(const tree_entry<KeyType, ItemType>& rhs) const; // TODO implement these overloads in SearchKey?
};


//#include "tree_entry.cc" // todo correct?
#endif //SOURCE_TREE_ENTRY_H

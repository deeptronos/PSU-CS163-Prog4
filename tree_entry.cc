
#include "tree_entry.h"


template<class KeyType, class ItemType>
void tree_entry<KeyType, ItemType>::setKey(const KeyType &sk) {
	searchKey = sk;
}



template<class KeyType, class ItemType>
tree_entry<KeyType, ItemType>::tree_entry() {} // default

//template<class KeyType, class ItemType>
//tree_entry<KeyType, ItemType>::tree_entry(KeyType search_key, ItemType new_item) : item(new_item), searchKey(search_key){} // using initializer
template<class KeyType, class ItemType>
tree_entry<KeyType, ItemType>::tree_entry(ItemType new_entry, KeyType search_key) : searchKey(search_key), item(new_entry) {}


template<class KeyType, class ItemType>
tree_entry<KeyType, ItemType>::~tree_entry() {} //default

template<class KeyType, class ItemType>
ItemType tree_entry<KeyType, ItemType>::getItem() const {
	return item;
}

template<class KeyType, class ItemType>
KeyType tree_entry<KeyType, ItemType>::getKey() const {
	return searchKey;
}

template<class KeyType, class ItemType>
void tree_entry<KeyType, ItemType>::setItem(const ItemType &newEntry) {
	item = newEntry;
}


template<class KeyType, class ItemType>
void tree_entry<KeyType, ItemType>::display() const {
	item.display(); // TODO only works for destination...
}



template <class KeyType, class ItemType>
bool tree_entry<KeyType, ItemType>::operator==(const tree_entry<KeyType, ItemType> &rhs) const {
	return(searchKey == rhs.getKey());
}

template <class KeyType, class ItemType>
bool tree_entry<KeyType, ItemType>::operator>(const tree_entry<KeyType, ItemType> &rhs) const { // todo check
	return(searchKey > rhs.getKey());
}

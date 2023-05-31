
#include "table.h"

template <class KeyType, class ItemType>
table<KeyType, ItemType>::table() : item_tree(nullptr) {} // default constructor using initializer

template <class KeyType, class ItemType>
table<KeyType, ItemType>::table(const table<KeyType, ItemType> &table_) : item_tree(table_.item_tree.copy_tree()) {} // TODO check
//table<KeyType, ItemType>::table(const table<KeyType, ItemType> &table_)  {
//	item_tree = table_.item_tree.copy_tree();
//}

template <class KeyType, class ItemType>
table<KeyType, ItemType>::~table(){
	clear(); // TODO valid?
}



template <class KeyType, class ItemType>
bool table<KeyType, ItemType>::add(const KeyType &search_key, const ItemType &new_item) {
	return item_tree.add(tree_entry<KeyType, ItemType>(new_item, search_key));
}

template <class KeyType, class ItemType>
bool table<KeyType, ItemType>::remove(const KeyType &search_key) {
	return item_tree.remove(tree_entry<KeyType, ItemType>(ItemType(), search_key));
}

template <class KeyType, class ItemType>
bool table<KeyType, ItemType>::isEmpty() const {
	return item_tree.isEmpty();
}

template <class KeyType, class ItemType>
int table<KeyType, ItemType>::getNumberOfItems() const {
	return item_tree.getNumberOfNodes();
}

template <class KeyType, class ItemType>
int table<KeyType, ItemType>::getHeight() const {
	return item_tree.getHeight();
}

template <class KeyType, class ItemType>
void table<KeyType, ItemType>::clear() {
	item_tree.clear();
}

template <class KeyType, class ItemType>
ItemType table<KeyType, ItemType>::getItem(const KeyType &search_key) const throw(NotFoundException) {
	return item_tree.getEntry(search_key); // TODO can this throw NotFoundException?
}

template <class KeyType, class ItemType>
bool table<KeyType, ItemType>::contains(const KeyType &search_key) const {
	return item_tree.contains(search_key);
}

template<class KeyType, class ItemType>
void table<KeyType, ItemType>::displayAll_byLocation() const { // TODO
    0;
}

template<class KeyType, class ItemType>
void table<KeyType, ItemType>::displayAll_byNaturalBeauty() const { // TODO
	0;
}

template <class KeyType, class ItemType>
void table<KeyType, ItemType>::traverse(void (*visit)(ItemType &)) const { // TODO check
	item_tree.inorderTraversal(visit);
}

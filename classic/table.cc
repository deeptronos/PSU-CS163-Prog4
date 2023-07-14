
#include "table.h"

// ---------------
// Private Methods
// ---------------
//
//template <class KeyType, class ItemType>
//void table<KeyType, ItemType>::traverseHelper(tree_entry<KeyType, ItemType>& the_entry ) { // TODO is this needed?
//	traverse_visit(the_entry.getItem());
//}


// ---------------------------
// Constructors and Destructor
// ---------------------------


//table<KeyType, ItemType>::table() : item_tree(nullptr) {} // default constructor using initializer
template <class KeyType, class ItemType>
table<KeyType, ItemType>::table() {
	item_tree = new binary_search_tree< tree_entry<KeyType, ItemType> >;
}

template <class KeyType, class ItemType>
table<KeyType, ItemType>::table(const table<KeyType, ItemType> &table_) : item_tree(table_.item_tree.copy_tree()) {} // TODO check
//table<KeyType, ItemType>::table(const table<KeyType, ItemType> &table_)  {
//	item_tree = table_.item_tree.copy_tree();
//}

template <class KeyType, class ItemType>
table<KeyType, ItemType>::~table(){ // TODO ok?
	delete item_tree;
}



// --------------
// Public Methods
// --------------

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
//	return item_tree.getEntry(search_key); // TODO can this throw NotFoundException?
//	return item_tree.getEntry(tree_entry<KeyType, ItemType>(ItemType(),search_key)); // Todo won't this just search item_tree for an entry whose item matches ItemType() ?
	tree_entry<KeyType, ItemType> entry_to_find(ItemType(), search_key);
	tree_entry<KeyType,ItemType> found_entry = item_tree.getEntry(entry_to_find);
	return found_entry.getItem();
}

template <class KeyType, class ItemType>
bool table<KeyType, ItemType>::contains(const KeyType &search_key) const {
	tree_entry<KeyType, ItemType> entry_to_find(ItemType(), search_key);
//	tree_entry<KeyType,ItemType> found_entry = item_tree.getEntry(entry_to_find);
	return item_tree.contains(entry_to_find);
}

template<class KeyType, class ItemType>
void table<KeyType, ItemType>::display() const{
	cout << "TABLE: " << endl << "  tree info: " << endl << "    # Data: " <<  item_tree.getNumberOfNodes() << ", Height: " << item_tree.getHeight() << endl;
}

template<class KeyType, class ItemType>
void table<KeyType, ItemType>::displayAll_byLocation() const { // TODO
    return;
}

template<class KeyType, class ItemType>
void table<KeyType, ItemType>::displayAll_byNaturalBeauty() const { // TODO
	return;
}

template <class KeyType, class ItemType>
void table<KeyType, ItemType>::traverse(void visit(tree_entry<KeyType, ItemType>&)) const { //First draft
	item_tree.inorderTraversal(visit);
}
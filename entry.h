
#ifndef SOURCE_ENTRY_H
#define SOURCE_ENTRY_H

class SearchKey{ // TODO should this just be a part of entry?

};

template <class KeyType, class ItemType>
class entry {
private:
	ItemType destination_item;
	KeyType searchKey;
protected:
	void setKey(const KeyType& searchKey); // Protected to prevent calling outside of member functions
	// TODO can we use void return types now??
public:
	entry();
	~entry();
	ItemType getItem() const;
	ItemType getKey() const;
	void setItem(const ItemType& newEntry);

	bool operator==(const entry<KeyType, ItemType>& rhs) const;
	bool operator>(const entry<KeyType, ItemType>& rhs) const; // TODO implement these overloads in SearchKey?
};


#endif //SOURCE_ENTRY_H

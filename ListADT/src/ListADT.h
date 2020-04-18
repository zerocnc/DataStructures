#include <inttypes.h>

// Header file for Unosrte list ADT

template<class T>
struct NodeType{
	T info;
	NodeType* next;
};


template<class T>
class UnsortedType {
public:

	UnsortedType() : length(0), listData(nullptr); // Class Constructor
	~UnsortedType(); // Class Deconstructor

	bool IsFull() const;

	uint32_t LenghtIs() const;

	void MakeEmpty();

	void RetrieveItem(T& item, bool& found);

	void InsertItem(T item);

	void DeleteItem(T item);

	void ResetUnsortedList();

	void GetNextItem(T& item);

private:
	uint32_t length;

	NodeType<T>* listData;
	NodeType<T>* currentPos;

};

// Determines whether the list is full.
// Post: Function value = (list is full)
template<class T>
bool UnsortedType<T>::IsFull() const {
	NodeType<ItemType>* ptr;
	ptr = new NodeType<T>;

	if (ptr == nullptr) {
		return true;
	}
	else {
		delete ptr;
		return false;
	}
}

// Post: List is empty; all items have been deallocated.
template<class T>
void UnsortedType<T>::MakeEmpty() {
	NodeType<T> tempPtr;

	while (listData != nullptr)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

// Pre: Key member(s) of of item is initialized.
// Post: If found, item's key matches an element's key in the list and a copy of that element has 
// been stored in item; otherwise, item is unchanged.
template<class T>
void UnsortedType<T>::RetrieveItem(T& item, bool& found) {
	bool moreToSearch;
	NodeType<T>* location;

	location = listData;
	found = false;
	moreToSearch = (location != nullptr);

	while (moreToSearch && !found) {
		if (item == location->info) {
			found = true;
			item = location->info;
		}
		else {
			location = location->next;
			moreToSearh = (moreToSearch != nullptr);
		}
	}
}

template<class T>
void UnsortedType<T>::InsertItem(T item) {
	NodeType<T>* location;

	location = new NodeType<T>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

template<class T>
void UnsortedType<T>::DeleteItem(T item) {
	NodeType<T>* location = listData;
	NodeType<T>* tempLocation;

	// Locate the node to delete
	if (item == listData->info) {
		tempLocation = location;
		listData = listData->next;	// Delete the first node.
	}
	else {
		while (!(item == (location->next)->info))
			location = location->next;
		
		// Delete the node at location.
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

template<class T>
void UnsortedType<T>::ResetUnsortedList() {
	currentPos = nullptr;
}

template<class T>
void UnsortedType<T>::GetNextItem(T& item) {
	if (currentPos == nullptr)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;
}

template<class T>
UnsortedType<T>::~UnsortedType(){

}
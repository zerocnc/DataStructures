#pragma once

#include <inttypes.h>

template<class T>
struct NodeList{
	T info;
	NodeList* next;
};

/*
*	Structure: The list elements are of T(type provide by user). This list has a special property
*	called the current position - the position of the last element accessed by GetNextItem
*	during an iteration through the list. Only ResetList and GetNextItem affect the current
*	position.
*/

template<class T>
class UnsortedType {
public:

	UnsortedType(); // Class Constructor
	~UnsortedType(); // Class Deconstructor

	bool IsFull() const;

	uint32_t LenghtIs() const;

	void MakeEmpty();
	void RetrieveItem(T& item, bool& found);
	void InsertItem(T item);
	void DeleteItem(T item);
	void ResetUnsortedList();
	void GetNextItem(T& item);
	bool IsEmpty();

private:
	uint32_t length;

	NodeList<T>* listData;
	NodeList<T>* currentPos;

};


template <class T>
UnsortedType<T>::UnsortedType()
{
	length = 0;
	listData = nullptr;
}

template<class T>
bool UnsortedType<T>::IsEmpty() {
	return (length == 0);
}

/// <summary>IsFull() determines whether list is full.</summary>
/// <returns>None</returns>
template<class T>
bool UnsortedType<T>::IsFull() const {
	NodeList<ItemType>* ptr;
	ptr = new NodeList<T>;

	if (ptr == nullptr) {
		return true;
	}
	else {
		delete ptr;
		return false;
	}
}

/// <summary>Determines the number of elements.</summary>
/// <typeparam name="T">- User specified type parameter.</typeparam>
/// <returns>length of type uint32_t.</returns>
template<class T>
uint32_t UnsortedType<T>::LenghtIs() const
{
	return length;
}

/// <summary>MakeEmpty() - Initalizes list to empty state</summary>
/// <returns>None.</returns>
template<class T>
void UnsortedType<T>::MakeEmpty() {
	NodeList<T> tempPtr;

	while (listData != nullptr)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

/// <summary>
/// RetrieveItem(...) retrieves list element whose key matches item's key (if present)
/// <para>Precondition: Key member(s) of of item is initialized.</para>
/// <para>Postcondition: If found, item's key matches an element's key in the list and a copy of that element has been stored in item; otherwise, item is unchanged.</para>
/// </summary>
/// <param name="item">: Storage for the value found.</param>
/// <param name="found">: Tells the user if key was found(true) or not in the list(false).</param>
template<class T>
void UnsortedType<T>::RetrieveItem(T& item, bool& found) {
	bool moreToSearch;
	NodeList<T>* location;

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
			moreToSearch = (moreToSearch != 0 );
		}
	}
}

/// <summary>
/// Insert(...) Adds item to list.
/// <para>Preconditions: List has been initalized. The list is not full.</para>
/// <para>Postcondition: item is in the list.</para>
/// </summary>
/// <param name="item">: item the user wants in the list.</param>
template<class T>
void UnsortedType<T>::InsertItem(T item) {
	NodeList<T>* location;

	location = new NodeList<T>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

/// <summary>
/// DeleteItem(...) deletes the element whose key matches item's key.
/// <para></para>
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="item"></param>
template<class T>
void UnsortedType<T>::DeleteItem(T item) {
	NodeList<T>* location = listData;
	NodeList<T>* tempLocation;

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

/// <summary>
/// ResetUnsortedList() Initializes current position for an iteration though the list.
/// <para>Precondition: Initializes current position for an iteration though the list.</para>
/// <para>Postcondition: Current position is prior to first element in list.</para>
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void UnsortedType<T>::ResetUnsortedList() {
	currentPos = nullptr;
}

/// <summary>
/// GetNextItem() Gets the next element in the list.
/// <para>Preconditon: List has been initialzed. Current position is defined. Element at current position is not last in list.
/// </para>
/// <para>Postcondition: Current position is updated to next position. item is a copy of element at current position.</para>
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="item">: copy of element at current position.</param>
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
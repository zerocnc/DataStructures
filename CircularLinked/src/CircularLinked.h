#include <inttypes.h>

template<class T>
struct NodeCircle {
	T info;
	NodeCircle* next;
};

// A list in which every node has a successor; the "last" element is succeeded by the "first" element.
template<class T>
class CircleType {
public:

	CircleType(); // Class Constructor
	~CircleType(); // Class Deconstructor

	bool IsFull() const;

	uint32_t LenghtIs() const;

	void MakeEmpty();

	void InsertItem(T item);
	void DeleteItem(T item);
	void View();

private:
	uint32_t length;

	NodeCircle<T>* listData;

};

// Initilizing constructor.
template <class T>
CircleType<T>::CircleType()
{
	length = 0;
	listData = nullptr;
}

// Deconstructor; deallocates cicular list.
template <class T>
CircleType<T>::~CircleType()
{
	MakeEmpty();
}

template <class T>
bool CircleType<T>::IsFull() const {
	NodeCircle<T>* ptr;
	ptr = new NodeCircle<T>;

	if (ptr == nullptr) {
		delete ptr;
		return true;
	}
	else {
		delete ptr;
		return false;
	}
}

template <class T>
uint32_t CircleType<T>::LenghtIs() const {
	return length;
}

template <class T>
void CircleType<T>::InsertItem(T item) {
	NodeCircle<T>* newNode;
	NodeCircle<T>* predLoc;
	NodeCircle<T>* location;
	bool found;

	newNode = new NodeCircle<T>;
	newNode->info = item;

	if (listData != nullptr)
	{
		FindItem(listData, item, location, predLoc, found);
		newNode->next = predLoc->next;
		predLoc->next = newNode;

		// if this is the last node in the list, re-assign listData.
		if (listData->info < item)
		{
			listData = newNode;
		}
	}
	else { // Inserting into an empty list.
		listData = newNode;
		newNode->next = newNode;
	}
	length++;
}

// Assumption: T is a type for which the operators "<" and "==" are defined-either an appropiate built-in type 
//			   or a class that overloads the operators.
// Pre: List is not empty.
// Post: If there is an element someItem whose key matches item's key, then found = true; otherwise
// found = false.
// If found, location conatins the address of someItem and predLoc contains the address of someItem predecessor;
// otherwise, location contains the address of item's logical successor and predLoc conains the address of item's
// logical predecessor.
template <class T>
void FindItem(NodeCircle<T>* listData, T item, NodeCircle<T>*& location, NodeCircle<T>*& predLoc, bool& found) {
	bool moreToSearch = true;

	location = listData->next;
	predLoc = listData;
	found = false;

	while (moreToSearch && !found) {
		if (item < location->info) {
			moreToSearch = false;
		}
		else if (item == location->info ) {
			found = true;
		}
		else {
			predLoc = location;
			location = location->next;
			moreToSearch = (location != listData->next);
		}
	}
}

template <class T>
void CircleType<T>::DeleteItem(T item) {
	NodeCircle<T>* location;
	NodeCircle<T>* predLoc;
	bool found;

	FindItem(listData, item, location, predLoc, found);

	if (predLoc == location) // Only node in list
		listData = nullptr;
	else {
		predLoc->next = location->next; // Deleted last node in list.
		if (location == listData)
			listData = predLoc;
	}
	delete location;
	length--;
}

template <class T>
void CircleType<T>::View() {
	NodeCircle<T>* location;

	location = listData;

	for (uint32_t ndx = 0; ndx < length; ndx++) {
		std::cout << location->info << '\t';
		location = location->next;
	}

}

template <class T>
void CircleType<T>::MakeEmpty() {
	NodeCircle<T>* tempPtr;

	for ( uint32_t ndx = 0; ndx < length; ndx++) {
		tempPtr = listData;
		listData = listData->next;

		delete tempPtr;
	}

	listData = nullptr;
	length = 0;
}


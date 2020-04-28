
template <class T>
struct NodeDLlist {
	T info;
	NodeDLlist<T>* next;
	NodeDLlist<T>* back;
};

template<class T>
class DLinkedLists {
public:

	DLinkedLists(); // Class Constructor
	~DLinkedLists(); // Class Deconstructor

	bool IsFull() const;

	uint32_t LenghtIs() const;

	void MakeEmpty();

	void RetrieveItem(T& item, bool& found);

	void InsertItem(T item);

	void DeleteItem(T item);

	void ResetUnsortedList();

	void GetNextItem(T& item);

	bool IsEmpty() const;

private:
	uint32_t length;

	NodeDLlist <T>* listData;
	NodeDLlist <T>* currentPos;

};

template<class T>
DLinkedLists<T>::DLinkedLists()
{
	listData = nullptr;
	currentPos = nullptr;
}

template<class T>
DLinkedLists<T>::~DLinkedLists()
{

}

template<class T>
bool DLinkedLists<T>::IsEmpty() const {
	return length;
}

template<class T>
bool DLinkedLists<T>::IsFull() const {

	NodeDLlIst<T>* tempPtr = new NodeDLlIst;

	if (tempPtr == nullptr) {
		delete tempPtr;
		return true;
	}
	else {
		delete tempPtr;
		return false;
	}
}

template<class T>
void FindItem(NodeDLlist<T>* listData, T item, NodeDLlist<T>*& location, bool& found) {
	bool moreToSearch = true;

	location = listData;
	found = false;

	while (moreToSearch && !found) {
		if (item < location->info)
			moreToSearch = false;
		else if (item == location->info)
			found = true;
		else { // !(x <= y) -> x > y
			location = location->next;
			moreToSearch = static_cast<bool>(location);
		}
	}
}

template<class T>
void DLinkedLists<T>::InsertItem(T item) {

	bool found = false;

	NodeDLlist<T>* tempPtr = new NodeDLlist<T>;
	tempPtr->info = item;

	// "AAAAAAAAAAAAAAAAAA"
	// "ZZZZZZZZZZZZZZZZZZ"

	FindItem( listData, item, currentPos, found);

	// Insert the first element.
	if ( (currentPos->next == nullptr) && (currentPos->back == nullptr))
	{

	}
	else if (found && currentPos ) {
		
	}
	else {

	}

	length++;

}

template<class T>
void DLinkedLists<T>::DeleteItem(T item) {

	length--;
}
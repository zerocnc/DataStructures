#pragma once

// Header file for Stack ADT

template<class T>
struct NodeType {
	T info;
	NodeType* next;
};

template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	void MakeEmpty();
	void Push(T);
	void Pop(T&);
	bool IsEmpty() const;
	bool IsFull();

private:
	unsigned int size;
	NodeType<T>* topPtr;

};

template<class T>
Stack<T>::Stack() : size(0) {
	topPtr = nullptr;
}

template<class T>
Stack<T>::~Stack() {
	MakeEmpty();
}

template<class T>
void Stack<T>::MakeEmpty() {
	
	NodeType<T>* tempPtr;

	while (topPtr != nullptr)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

// Adds newItem to the top of the stack.
// Pre: Stack has been initilized and is not full.
// Post: item is at top of stack.
template<class T>
void Stack<T>::Push(T newItem) {
	NodeType<T>* location;

	location = new NodeType<T>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

template<class T>
void Stack<T>::Pop(T& item) {
	NodeType<T>* tempPtr;

	item = topPtr->info;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	
	delete tempPtr;
}

template<class T>
bool Stack<T>::IsEmpty() const{
	return (topPtr == nullptr);
}

template<class T>
bool Stack<T>::IsFull() {
	NodeType<T>* location;

	location = new NodeType<T>;
	if (location == nullptr)
		return true;
	else
	{
		delete location;
		return false;
	}
}
#ifndef LIST_H
#define LIST_H

#include <iostream> 

template<typename T>
class Node
{
private:
	T data;
	Node* nextElement;
	Node* prevElement;
public:
	Node(); // Default ctor
};

template<typename T>
Node<T>::Node() : nextElement(nullptr), prevElement(nullptr) {}

template<typename T>
class DoublyLinkList {
private:
	Node* head;
public:
	bool isEmpty();
};

template<typename T>
bool DoublyLinkList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

#endif

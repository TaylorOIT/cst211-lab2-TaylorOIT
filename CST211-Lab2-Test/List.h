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
	DoublyLinkList();
	bool isEmpty(); // checks if the link list is empty

};

template<typename T>
DoublyLinkList<T>::DoublyLinkList() : head(nullptr) {}

template<typename T>
bool DoublyLinkList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

#endif

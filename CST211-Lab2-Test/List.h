#ifndef LIST_H
#define LIST_H

#include <iostream> 

template<typename T>
class Node
{
public:
	T data;
	Node* nextElement;
	Node* prevElement;
	Node(); // Default ctor
};

template<typename T>
Node<T>::Node() : nextElement(nullptr), prevElement(nullptr) {}

template<typename T>
class DoublyLinkList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DoublyLinkList(); // default constructor
	bool isEmpty(); // checks if the link list is empty
	void Prepend(T data); // add data at the front of the link list

};

template<typename T>
DoublyLinkList<T>::DoublyLinkList() : head(nullptr),tail(nullptr) {}

template<typename T>
bool DoublyLinkList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
void DoublyLinkList<T>::Prepend(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->prevElement = nullptr;
	newNode->nextElement = head;
	if (head != nullptr) {
		head->prevElement = newNode;
	}
	head = newNode;
	std::cout << data << " inserted at front of list!" << std::endl;

}

#endif

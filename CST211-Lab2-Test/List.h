#ifndef LIST_H
#define LIST_H

#include <iostream> 
using std::cout;
using std::endl;

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
	void PrintForwards(); // prints the entire link list forwards
	const T& First(); // returns the first element in the link list
	const T& Last(); // return the last element in the link list

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
	cout << data << " inserted at front of list!" << endl;

}

template<typename T>
void DoublyLinkList<T>::PrintForwards()
{
	if (isEmpty()) {
		cout << "List is Empty!" << endl;
	}
	else
	{
		Node<T>* temp = head;   // temp points to head of the list
		cout << "List : ";

		while (temp != nullptr) {    // traverse through the list
			cout << temp->data << " -> ";
			temp = temp->nextElement;
		}
		cout << "null " << endl;
	}

}

template<typename T>
const T& DoublyLinkList<T>::First()
{
	Node<T>* curr = head;
	curr->nextElement;
	return curr->data;
}

template<typename T>
const T& DoublyLinkList<T>::Last()
{
	Node<T>* curr = head;
	curr->nextElement;
	while (curr->nextElement != nullptr) {
		curr = curr->nextElement;
	}
	return curr->data;
}

#endif

#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include "Exception.h"
using std::cout;
using std::endl;

template<typename T>
class Node
{
public:
	T data;
	Node* nextElement;
	Node* prevElement;
	Node(); // default constructor
};

template<typename T>
Node<T>::Node() : data(), nextElement(nullptr), prevElement(nullptr) {}

template<typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List(); // default constructor
	List(const List<T>& copy); // copy constructor
	~List(); // destructer
	void Purge(); // deletes the entire linklist
	void Extract(T data); // deletes a selected element in the link list
	bool isEmpty(); // checks if the link list is empty
	void Prepend(T data); // add data at the front of the link list
	void Append(T data); // add data at the end of the link list
	void InsertAfter(T new_item,T existing_item); // inserts after existing item in link list
	void InsertBefore(T new_item, T existing_item); // inserts before existing item in link list
	void PrintForwards(); // prints the entire link list forwards
	void PrintBackwards(); // print the entire link list backwards
	const T& First(); // returns the first element in the link list
	const T& Last(); // return the last element in the link list

	Node<T>* getHead();
	Node<T>* getTail();
	
};

template<typename T>
List<T>::List() : head(nullptr) {}

template<typename T>
List<T>::List(const List<T>& copy)
{
	Node<T>* curr = copy.head;
	while (curr != nullptr) {
		Append(curr->data);
		curr = curr->nextElement;
	}
}

template<typename T>
List<T>::~List()
{
	Node<T>* curr = head;
	if (curr != nullptr)
		curr = curr->nextElement;
	while (head != nullptr) {
		curr = head;
		head = head->nextElement;
		delete curr;
	}
}

template<typename T>
void List<T>::Purge()
{
	Node<T>* curr = head;
	while (head != nullptr) {
		curr = head;
		head = head->nextElement;
		delete curr;
	}
}

template<typename T>
void List<T>::Extract(T data)
{
	if (isEmpty() == true)
		throw(Exception("The link list is empty!"));
	
	Node<T>* curr = head;
	Node<T>* prev = nullptr;

	bool deleted = false;

	if (curr->data == data) {
		head = head->nextElement;
		delete curr;
		deleted = true;
	}

	while (curr != nullptr && deleted == false) {
		if (data == curr->data) {
			prev->nextElement = curr->nextElement;
			delete curr;
			deleted = true;
			curr = prev->nextElement;
			break;
		}
		prev = curr;
		curr = curr->nextElement;
	}

	if (deleted == false)
		throw(Exception("The value does not exist!"));
}

template<typename T>
bool List<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
void List<T>::Prepend(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->nextElement = head;
	if (head != nullptr) {
		head->prevElement = newNode;
	}
	head = newNode;

}

template<typename T>
void List<T>::Append(T data)
{
	if (isEmpty() != true) {
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		Node<T>* curr = head;
		while (curr->nextElement != nullptr) {
			curr = curr->nextElement;
			newNode->prevElement = curr;
		}

		curr->nextElement = newNode;
	}
	else
	{
		Prepend(data);
	}
}

template<typename T>
void List<T>::InsertAfter(T new_item, T existing_item)
{
	bool Inserted = false;

	if (isEmpty() == true)
		throw(Exception("The link list is empty!"));
	
	Node<T>* newNode = new Node<T>;
	newNode->data = new_item;

	Node<T>* curr = head;
	while (curr != nullptr) {
		if (curr->data == existing_item) {
			newNode->prevElement = curr;
			newNode->nextElement = curr->nextElement;
			curr->nextElement = newNode;
			Inserted = true;
			break;
		}
		else
			curr = curr->nextElement;
	}

	if (Inserted == false)
		throw(Exception("The existing item does not exist!"));
}

template<typename T>
void List<T>::InsertBefore(T new_item, T existing_item)
{
	bool Inserted = false;
	
	if (isEmpty() == true)
		throw(Exception("The link list is empty!"));

	Node<T>* newNode = new Node<T>;
	newNode->data = new_item;


	Node<T>* curr = head;
	Node<T>* temp = curr;
	temp = temp->nextElement;

	if (head->data == existing_item) {
		Prepend(new_item);
		return;
	}
	// if head is equal to the existing item, append at front of list.


	while ((curr != nullptr) && (temp != nullptr)) {
		if (temp->data == existing_item) {
			newNode->prevElement = curr;
			newNode->nextElement = curr->nextElement;
			curr->nextElement = newNode;
			Inserted = true;
			break;
		}
		else {
			curr = curr->nextElement;
			temp = temp->nextElement;
		}
	}

	if (Inserted == false)
		throw(Exception("The existing item does not exist!"));

}

template<typename T>
void List<T>::PrintForwards()
{
	if (isEmpty()) {
		cout << "List is Empty!" << endl;
	}
	else
	{
		Node<T>* temp = head;
		cout << "List : ";

		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->nextElement;
		}
		cout << "null " << endl;
	}

}

template<typename T>
void List<T>::PrintBackwards()
{
	Node<T>* tail = head;
	while (tail->nextElement != nullptr) {
		tail = tail->nextElement;
	}
	cout << "List : ";
	while (tail != nullptr) {
		cout << tail->data << " -> ";
		tail = tail->prevElement;
	}
	cout << "null " << endl;
}

template<typename T>
const T& List<T>::First()
{
	if (isEmpty() == true)
	{
		throw(Exception("The link list is empty!"));
	}
		Node<T>* curr = head;
		curr->nextElement;
		return curr->data;
}

template<typename T>
const T& List<T>::Last()
{
	if (isEmpty() == true)
		throw(Exception("The link list is empty!"));
	Node<T>* curr = head;
	while (curr->nextElement != nullptr) {
		curr = curr->nextElement;
	}
	return curr->data;
}

template<typename T>
Node<T>* List<T>::getHead()
{
	return head;
}

template<typename T>
Node<T>* List<T>::getTail()
{
	return tail;
}

#endif

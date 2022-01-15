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
	Node(); // default constructor
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
	~DoublyLinkList(); // destructer
	void Purge(); // deletes the entire linklist
	void Extract(T data);
	bool isEmpty(); // checks if the link list is empty
	void Prepend(T data); // add data at the front of the link list
	void Append(T data); // add data at the end of the link list
	void InsertAfter(T new_item,T existing_item); // inserts after existing item in link list
	void PrintForwards(); // prints the entire link list forwards
	void PrintBackwards(); // print the entire link list backwards
	const T& First(); // returns the first element in the link list
	const T& Last(); // return the last element in the link list
	
};

template<typename T>
DoublyLinkList<T>::DoublyLinkList() : head(nullptr),tail(nullptr) {}

template<typename T>
DoublyLinkList<T>::~DoublyLinkList()
{
	Node<T>* curr = head;
	if (curr != nullptr)
		curr = curr->nextElement;
	cout << "---------------------------------------------------" << endl;
	cout << "~DoublyLinkList" << endl;
	PrintForwards();
	while (head != nullptr) {
		curr = head;
		head = head->nextElement;
		delete curr;
		PrintForwards();
	}
	cout << "---------------------------------------------------" << endl;
}

template<typename T>
void DoublyLinkList<T>::Purge()
{
	Node<T>* curr = head;
	while (head != nullptr) {
		curr = head;
		head = head->nextElement;
		delete curr;
	}
}

template<typename T>
void DoublyLinkList<T>::Extract(T data)
{
	Node<T>* curr = head;
	Node<T>* prev = nullptr;

	bool deleted = false;

	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return; 
	}

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

	if (deleted == false) {
		cout << data << " does not exist!" << endl;
	}
	else {
		cout << data << " was deleted!" << endl;
	}
}

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
	newNode->nextElement = head;
	if (head != nullptr) {
		head->prevElement = newNode;
	}
	head = newNode;
	cout << data << " inserted at front of list!" << endl;

}

template<typename T>
void DoublyLinkList<T>::Append(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	
	Node<T>* curr = head;
	while (curr->nextElement != nullptr) {
		curr = curr->nextElement;
		newNode->prevElement = curr;
	}

	curr->nextElement = newNode;
	cout << data << " inserted at back of list!" << endl;
}

template<typename T>
void DoublyLinkList<T>::InsertAfter(T new_item, T existing_item)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = new_item;

	Node<T>* curr = head;
	while (curr != nullptr) {
		if (curr->data == existing_item) {
			newNode->prevElement = curr;
			newNode->nextElement = curr->nextElement;
			curr->nextElement = newNode;
			break;
		}
		else
			curr = curr->nextElement;
	}
}

template<typename T>
void DoublyLinkList<T>::PrintForwards()
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
void DoublyLinkList<T>::PrintBackwards()
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
	while (curr->nextElement != nullptr) {
		curr = curr->nextElement;
	}
	return curr->data;
}

#endif

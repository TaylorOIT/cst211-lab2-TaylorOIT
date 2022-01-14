#ifndef LIST_H
#define LIST_H

template<typename T>
class Node
{
	T data;
	Node* nextElement;
	Node* prevElement;
};

template<typename T>
Node<T>::Node() : nextElement(nullptr), prevElement(nullptr) {}

#endif

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
template<typename T>
int LinkedList<T>::size = 0;

template<typename T>
void LinkedList<T>::copy(const LinkedList<T> & other) {
	Node * otherRoot = other.root;
	if (otherRoot) {
		root = new Node();
		root->data = other.root->data;
	}
	else {
		root = NULL;
		return;
	}
	Node * currentNode = root;
	otherRoot = other.root->next;
	while (!currentNode) {
		Node *nextNode = new Node();
		nextNode->data = otherRoot->data;
		currentNode->next = nextNode;
		currentNode = nextNode;
		otherRoot = otherRoot->next;
	}
}
template<typename T>
void LinkedList<T>::Delete() {
	Node<T> * node = root;
	while (!node) {
		Node<T> * forDelete = node;
		node = node->next;
		delete forDelete;
	}
}
template<typename T>
LinkedList<T>::LinkedList() : root(NULL) {
	root = new Node<T>();
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & other) {
	copy(other);
}
template<typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & other) {
	if (this != &other) {
		Delete();
		copy(other);
	}
	return *this;
}
template<typename T>
LinkedList<T>::~LinkedList() {
	Delete();
}
template<typename T>
bool LinkedList<T>::empty() const {
	if (!root)
		return true;
	else return false;
}

template<typename T>
int LinkedList<T>::Size() const {
	return size;
}

template<typename T>
Node<T> * LinkedList<T>::lookup(int index) const {
	Node<T> * currentNode = root;
	while (currentNode != NULL && index > 0) {
		currentNode = currentNode->next;
		--index;
	}
	return currentNode;
}

template<typename T>
Node<T> * LinkedList<T>::getAt(int index) const {
	return lookup(index);
}

template<typename T>
void LinkedList<T>::insertAtBeginning(T _data) {
	Node<T>* newNode = new Node<T>();
	newNode->data = _data;

	newNode->next = root;
	root = newNode;
	++size;
}

template<typename T>
void LinkedList<T>::insertToEnd(T _data) {
	Node<T> * newNode = new Node<T>();
	newNode->data = _data;

	Node<T> * lastNode = lookup(size-1);
	lastNode->next = newNode;
	++size;
}

template<typename T>
void LinkedList<T>::insertBefore(T _data,T element) {
	Node<T> * newNode = new Node<T>();
	newNode->data = _data;
	Node<T> * nodes = root;
	int index = 0;
	while (nodes->data != element) {
		nodes = nodes->next;
		++index;
	}
	if (index == 0) {
		--size;
		insertAtBeginning(_data);
	}
	else {
		Node<T> * nodeBefore = lookup(index);
		Node<T> * afterNode = nodeBefore->next;
		nodeBefore->next = newNode;
		newNode->next = afterNode;
	}
	++size;
}
template<typename T>
void LinkedList<T>::insertAfter(T _data,T element) {
	Node<T> * newNode = new Node<T>();
	newNode->data = _data;
	Node<T> * nodes = root;
	int index = 0;
	while (nodes->data != element) {
		nodes = nodes->next;
		++index;
	}
	Node<T> * nodeBefore = lookup(index);
	Node<T> * afterNode = nodeBefore->next;
	nodeBefore->next = newNode;
	newNode->next = afterNode;
	++size;
}

template<typename T>
void LinkedList<T>::removeAt(int index) {
	Node<T> *getNode = lookup(index-1);
	if (index > 1) {
		Node<T> *getPrevious = lookup(index - 2);
		getPrevious->next = getNode->next;
		delete getNode;
	}
	else {
		root = root->next;
	}
	--size;
}

template<typename T>
void::LinkedList<T>::removeBefore(T element) {
	int index = 0;
	Node * nodes = root;
	while (nodes->data != element) {
		nodes = nodes->next;
		++index;
	}
	removeAt(index);
}

template<typename T>
void::LinkedList<T>::removeAfter(T element) {
	int index = 1;
	Node<T> * nodes = root;
	while (nodes->data != element) {
		nodes = nodes->next;
		++index;
	}
	Node<T> *getNode = lookup(index);
	Node<T> *getPrevious = lookup(index - 1);
	getPrevious->next = getNode->next;
	delete getNode;
	--size;
}

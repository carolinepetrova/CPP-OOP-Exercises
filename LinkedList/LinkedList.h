#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template<typename T>
struct Node {
	T data;
	Node * next;
};
template <typename T>
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	LinkedList & operator=(const LinkedList<T>&);
	~LinkedList();

	bool empty() const;
	int Size() const;
	Node<T> * getAt(int) const;
	void insertAtBeginning(T);
	void insertToEnd(T);
	void insertBefore(T,T); //inserts before some element
	void insertAfter(T, T); //inserts after some element
	void removeAt(int);
	void removeBefore(T);
	void removeAfter(T);
	Node<T> * lookup(int) const;

private:

	void Delete();
	void copy(const LinkedList<T>&);

	Node<T> * root;
	static int size;
};

#include "LinkedList.hpp"

#endif

#pragma once

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

class Vector {
public:
	Vector(); // default constructor
	Vector(const Vector&); //copy constructor
	Vector & operator=(const Vector &); //operator =
	~Vector(); //destructor

	void pushBack(int);
	void popBack(); // removes last element
	void insertAt(int,int);
	void removeAt(int);
	int Size() const;

	bool elementExists(int) const;
	bool empty() const;
	
	void print() const;

private:
	void copyVector(const Vector &);
	void deleteData();
	void extendCapacity();

	int size;
	int capacity;
	int * container;
};

#endif

#pragma once

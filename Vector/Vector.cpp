#include "stdafx.h"
#include "Vector.h"

const int INITIAL_VEC_SIZE = 1;

Vector::Vector() {
	this->container = new int[INITIAL_VEC_SIZE];
	this->capacity = INITIAL_VEC_SIZE;
}

Vector::Vector(const Vector & other) {
	this->copyVector(other);
}

Vector & Vector::operator=(const Vector & other) {
	if (this != &other) {
		this->deleteData();
		this->copyVector(other);
	}
	return *this;
}

Vector::~Vector() {
	this->deleteData();
}

void Vector::pushBack(int elem) {
	if (this->capacity == this->size) {
		this->extendCapacity();
	}
	container[size] = elem;
	++size;
}

void Vector::popBack() {
	--size;
}

void Vector::insertAt(int position, int element) {
	if (position > this->capacity || position>this->size) {
		throw("Invalid Position");
	}
	if (this->size >= this->capacity) {
		this->extendCapacity();
	}
	for (int i = size-1; i >position; --i) {
		this->container[i] = container[i - 1];
	}
	this->container[position] = element;
	++this->size;
}

void Vector::removeAt(int position) {
	if (position > this->capacity || position>this->size) {
		throw("Invalid Position");
	}
	for (int i = 0; i < this->size; i++) {
		if (i == position) {
			for (int j = i; j < size - 1; i++) {
				this->container[j] = this->container[j + 1];
			}
		}
	}
	--this->size;
}

int Vector::Size() const {
	return this->size;
}

bool Vector::elementExists(int element) const {
	for (int i = 0; i < this->size; i++) {
		if (this->capacity == element) {
			return true;
		}
	}
	return false;
}

bool Vector::empty() const {
	if (this->size == 0) {
		return true;
	}
	return false;
}

void Vector::copyVector(const Vector&other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->container = new int[this->size];
	for (int i = 0; i < other.capacity; i++) {
		this->container[i] = other.container[i];
	}
}

void Vector::deleteData() {
	delete[] this->container;
}

void Vector::extendCapacity() {
	int * buffer = this->container;
	this->container = new int[this->capacity * 2];
	this->capacity *= 2;
	for (int i = 0; i < size; ++i) {
		this->container[i] = buffer[i];
	}
	delete[] buffer;
}

void Vector::print() const {
	for (int i = 0; i < size; ++i) {
		std::cout << container[i] << std::endl;
	}
}
#include "stdafx.h"
#include "Luggage.h"
#include <iostream>

int Luggage::uID = 0;

Luggage::Luggage(double _capacity, int _numOfItems, double _weight) {
	this->setID();
	this->setCapacity(_capacity);
	this->setNumOfItems(_numOfItems);
	this->setWeight(_weight);
}

void Luggage::setID() {
	uID++;
	this->id = uID;
}

void Luggage::setCapacity(double _capacity) {
	if (_capacity < 0)
		_capacity = 0;
	this->capacity = _capacity;
}

void Luggage::setNumOfItems(int _numOfItems) {
	if (_numOfItems < 0)
		_numOfItems = 0;
	this->numOfItems = _numOfItems;
}

void Luggage::setWeight(double _weight) {
	if (_weight < 0)
		_weight = 0;
	this->weight = _weight;
}

int Luggage::getID() const {
	return this->id;
}

double Luggage::getCapacity() const {
	return this->capacity;
}

double Luggage::getWeight() const {
	return this->weight;
}

int Luggage::getNumOfItems() const {
	return this->numOfItems;
}

void Luggage::print() const {
	std::cout << "Luggage ID: " <<  this->getID() << std::endl;
	std::cout << "Luggage capacity: " << this->getCapacity() << std::endl;
	std::cout << "Luggage num of items: " << this->getNumOfItems() << std::endl;
	std::cout << "Luggage weight: " << this->getWeight() << std::endl;
}
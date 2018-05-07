#include "stdafx.h"
#include "TravelGroup.h"
#include <iostream>


TravelGroup::TravelGroup(int _numOfPassengers, const Passenger * _arrOfPassengers): numOfPassengers(0), arrOfPassengers(NULL) {
	this->setNumOfPassengers(_numOfPassengers);
	this->setArrOfPassengers(_arrOfPassengers, _numOfPassengers);
}

TravelGroup::TravelGroup(const TravelGroup& other) {
	this->setNumOfPassengers(other.numOfPassengers);
	arrOfPassengers = new Passenger[other.numOfPassengers];
	for (int i = 0; i < other.numOfPassengers; ++i) {
		this->arrOfPassengers[i] = other.arrOfPassengers[i];
	}
}

TravelGroup& TravelGroup::operator= (const TravelGroup & other) {
	if (this != &other)
	{
		this->setNumOfPassengers(other.numOfPassengers);
		arrOfPassengers = new Passenger[other.numOfPassengers];
		for (int i = 0; i < other.numOfPassengers; ++i) {
			this->arrOfPassengers[i] = other.arrOfPassengers[i];
		}
	}
	return *this;
}

TravelGroup::~TravelGroup() {
	delete[] this->arrOfPassengers;
}

void TravelGroup::setNumOfPassengers(int _numOfPassengers) {
	if (_numOfPassengers < 0)
		_numOfPassengers = 0;
	this->numOfPassengers = _numOfPassengers;
}

void TravelGroup::setArrOfPassengers(const Passenger * _arrOfPassengers, int _numOfPassengers) {
	arrOfPassengers = new Passenger[_numOfPassengers];
	for (int i = 0; i < _numOfPassengers; i++) {
		this->arrOfPassengers[i] = _arrOfPassengers[i];
		
	}
}

int TravelGroup::getNumOfPassengers() const {
	return this->numOfPassengers;
}

void TravelGroup::getArrOfPassengers() const {
	for (int i = 0; i < numOfPassengers; i++) {
		arrOfPassengers[i].print();
		std::cout << std::endl;
	}
}


void TravelGroup::sortByWeightOfLuggage() {
	for (int i = 0; i < numOfPassengers - 1; ++i)
	{
		int indexMin = i;
		for (int j = i + 1; j < numOfPassengers; ++j)
		{
			if (arrOfPassengers[j].getLuggage().getWeight() < arrOfPassengers[indexMin].getLuggage().getWeight()) {
				indexMin = j;
			}
		}
		if (indexMin != i)
		{
			Passenger helpPassenger = arrOfPassengers[i];
			arrOfPassengers[i] = arrOfPassengers[indexMin];
			arrOfPassengers[indexMin] = helpPassenger;
		}
	}
}

void TravelGroup::PeopleWhoTravelFromSameStop(const char * CheckFirstStop) {
	for (int i = 0; i < numOfPassengers; i++) {
		if (strcmp(arrOfPassengers[i].getTicket().getFirstStop(), CheckFirstStop) == 0) {
			std::cout << arrOfPassengers[i].getName() << std::endl;
		}
	}
}

void TravelGroup::PeopleWhoTravelToSameDestination(const char * CheckDestination) {
	for (int i = 0; i < numOfPassengers; i++) {
		if (strcmp(arrOfPassengers[i].getTicket().getDestination(), CheckDestination) == 0) {
			std::cout << arrOfPassengers[i].getName() << std::endl;
		}
	}
}

void TravelGroup::recursiveArray(int num, Passenger * arr) const{
	std::cout << arr[0].getName() << std::endl;
	if (num == 1) return;
	recursiveArray( num - 1,arr + 1);
}

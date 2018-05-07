#include "stdafx.h"
#include <iostream>
#include "Ticket.h"
#include "Luggage.h"
#include "Passenger.h"

int Passenger::passengersCounter = 0;

Passenger::Passenger(const char * _name, const Ticket& _ticket,const Luggage& _luggage):name(NULL), ticket2("", "", 0, car), luggage2(0, 0, 0) {
	this->setName(_name);
	this->setTicket(_ticket);
	this->setLuggage(_luggage);
	passengersCounter++;
}

Passenger::Passenger(const Passenger& other) {
	copyPassenger(other);
}

Passenger& Passenger::operator= (const Passenger& _passenger) {
	if (this != &_passenger)
	{
		
		copyPassenger(_passenger);
	}
	return *this;
}

Passenger::~Passenger() {
	this->deletePassenger();
}

void Passenger::setName(const char * _name) {
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Passenger::setTicket(const Ticket & _ticket) {
	this->ticket2 = _ticket;
}

void Passenger::setLuggage(const Luggage& _luggage) {
	this->luggage2 = _luggage;
	
}

const char * Passenger::getName() const {
	return this->name;
}

Ticket Passenger::getTicket() const {
	return this->ticket2;
}

Luggage Passenger::getLuggage() const {
	return this->luggage2;
}


void Passenger::print() const {
	std::cout << "Passenger name: " << this->getName() << std::endl;
	std::cout << "Passenger ticket: " << std::endl; this->getTicket().print();
	std::cout << "Passenger Luggage: " << std::endl; this->getLuggage().print();
	std::cout << "Number of passengers: " << this->countPassengers() << std::endl;
}


void Passenger::copyPassenger(const Passenger&_passenger) {
	passengersCounter++;
	this->setName(_passenger.name);
	this->setTicket(_passenger.ticket2);
	this->setLuggage(_passenger.luggage2);
}

void Passenger::deletePassenger() {
	passengersCounter--;
	delete[] this->name;
}

bool Passenger::isTheFirstStopSame(const Passenger& other) {
	if (strcmp(this->getTicket().getFirstStop(), other.getTicket().getFirstStop()) == 0) {
		return true;
	}
	return false;
}

bool Passenger::areTravellingToSamePlace(const Passenger& other) {
	if (strcmp(this->getTicket().getDestination(), other.getTicket().getDestination()) == 0) {
		return true;
	}
	return false;
}
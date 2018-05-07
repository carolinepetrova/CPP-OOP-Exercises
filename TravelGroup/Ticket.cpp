#include "stdafx.h"
#include "Ticket.h"
#include <iostream>

Ticket::Ticket(const char * _firstStop,const char * _destination, int _priceOfTicket, Vehicles _typeOfVehicle)
	:firstStop(NULL),destination(NULL),priceOfTicket(0),typeOfVehicle(car){
	this->SetFirstStop(_firstStop);
	this->SetDestination(_destination);
	this->setPrice(_priceOfTicket);
	this->setVehicle(_typeOfVehicle);
}

Ticket::Ticket(const Ticket& ticket):
	Ticket(ticket.firstStop,ticket.destination,ticket.priceOfTicket, ticket.typeOfVehicle) {}


Ticket& Ticket::operator= (const Ticket& _ticket) {
	if (this != &_ticket)
	{
		this->copyTicket(_ticket);
	}
	return *this;
}

Ticket::~Ticket() {
	this->deleteTicket();
}

void Ticket::SetFirstStop(const char * _firstStop) {
	delete[] firstStop;
	this->firstStop = new char[strlen(_firstStop) + 1];
	strcpy_s(this->firstStop, strlen(_firstStop) + 1, _firstStop);
}

void Ticket::SetDestination(const char * _destination) {
	delete[] destination;
	this->destination = new char[strlen(_destination) + 1];
	strcpy_s(this->destination, strlen(_destination) + 1, _destination);
}

void Ticket::setPrice(int _price) {
	if (_price < 0) {
		_price = 0;
	}
	this->priceOfTicket = _price;
}

void Ticket::setVehicle(Vehicles _typeOfVehicle) {
	this->typeOfVehicle = _typeOfVehicle;
}

const char * Ticket::getFirstStop() const {
	return this->firstStop;
}

const char * Ticket::getDestination() const {
	return this->destination;
}

int Ticket::getPrice() const {
	return this->priceOfTicket;
}

Vehicles Ticket::getVehicle() const {
	return this->typeOfVehicle;
}

void Ticket::print() const {
	std::cout<< "First stop: " << this->getFirstStop() << std::endl;
	std::cout << "Destination: " << this->getDestination() << std::endl;
	std::cout << "Price: " << this->getPrice() << std::endl;
	std::cout << "Vehicle: ";
	switch (this->getVehicle()) {
	case 1:
		std::cout << "train" << std::endl;
		break;
	case 2:
		std::cout << "plane" << std::endl;
		break;
	case 3:
		std::cout << "bus" << std::endl;
		break;
	case 4:
		std::cout << "car" << std::endl;
		break;
	case 5:
		std::cout << "boat" << std::endl;
		break;
	}
}

void Ticket::deleteTicket() {
	delete[] this->firstStop;
	delete[] this->destination;
}

void Ticket::copyTicket(const Ticket& _ticket) {
	this->SetFirstStop(_ticket.firstStop);
	this->SetDestination(_ticket.destination);
	this->setPrice(_ticket.priceOfTicket);
	this->setVehicle(_ticket.typeOfVehicle);
}
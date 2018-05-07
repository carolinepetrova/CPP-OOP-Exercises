#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#pragma once
enum Vehicles { train, plane, bus, car, boat };

class Ticket {
public:
	Ticket(const char * _firstStop="",const char * _destination="", int _priceOfTicket=0, Vehicles _typeOfVehicle=car);
	Ticket(const Ticket& _ticket);
	Ticket& operator= (const Ticket& _ticket);
	~Ticket();

	void SetFirstStop(const char * _firstStop);
	void SetDestination(const char * _destination);
	void setPrice(int _price);
	void setVehicle(Vehicles _typeOfVehicle);

	const char * getFirstStop() const;
	const char * getDestination() const;
	int getPrice() const;
	Vehicles getVehicle() const;
	void print() const;

private:
	void copyTicket(const Ticket& _ticket);
	void deleteTicket();


	char * firstStop;
	char * destination;
	int priceOfTicket;
	Vehicles typeOfVehicle;

};

#endif

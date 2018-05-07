#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include "Ticket.h"
#include "Luggage.h"
#include <iostream>

class Passenger {
public:
	Passenger(const char* name = "", const Ticket& _ticket = Ticket("","",0,car), const Luggage& _luggage = Luggage(0,0,0));
	Passenger(const Passenger& _passenger);
	Passenger& operator= (const Passenger& _passenger);
	~Passenger();

	void setName(const char * _name);
	void setLuggage(const Luggage & _luggage);
	void setTicket(const Ticket & _ticket);

	const char * getName() const;
	Luggage getLuggage() const;
	Ticket getTicket() const;
	void print() const;

	static int countPassengers() {
		return passengersCounter;
	}

	bool isTheFirstStopSame(const Passenger&);
	bool areTravellingToSamePlace(const Passenger&);

private:
	void copyPassenger(const Passenger& _passenger);
	void deletePassenger();

	static int passengersCounter;
	char * name;
	Luggage luggage2;
	Ticket ticket2;
};

#endif
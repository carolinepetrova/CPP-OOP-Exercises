#ifndef TRAVELGROUP_H_INCLUDED
#define TRAVELGROUP_H_INCLUDED
#include "Passenger.h"
#pragma once

class TravelGroup  {
public:
	TravelGroup(int _numOfPassengers = 0, const Passenger * _arrOfPassengers = NULL);
	TravelGroup(const TravelGroup&); 
	TravelGroup& operator= (const TravelGroup& other); 
	~TravelGroup();

	void setNumOfPassengers(int);
	void setArrOfPassengers(const Passenger *,int);


	int getNumOfPassengers() const;
	void getArrOfPassengers() const;

	void sortByWeightOfLuggage();
	void PeopleWhoTravelFromSameStop(const char *);
	void PeopleWhoTravelToSameDestination(const char *);
	void recursiveArray(int,Passenger*) const;

private:

	int numOfPassengers;
	Passenger * arrOfPassengers;
};

#endif
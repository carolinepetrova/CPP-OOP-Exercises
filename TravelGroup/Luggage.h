#ifndef LUGGAGE_H_INCLUDED
#define LUGGAGE_H_INCLUDED
#pragma once

class Luggage {
public:
	Luggage(double _capacity = 0,int _numOfItems = 0,double _weight = 0);

	void setCapacity(double _capacity);
	void setNumOfItems(int _numOfItems);
	void setWeight(double _weight);
	void setID();

	int getID() const;
	double getCapacity() const;
	int getNumOfItems() const;
	double getWeight() const;
	void print() const;

private:
	static int uID;
	double capacity;
	int numOfItems;
	double weight;
	int id;
};

#endif

#pragma once
#include"Date.h"

class Room
{

	char* reservationName;
	int id;
	int numberBeds;
	bool isOccupied;
	Interval *interval;
	bool isClosed;
	//void copyFrom(const Room&);
	//void free();

public:

	Room();
	void setReservationName(const char*);
	void setNumberBeds(const int);
	void setInterval(const Interval);
	void setIsOccupied(const bool);
	void setIsClosed(const bool);
	~Room();


};
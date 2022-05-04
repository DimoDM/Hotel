#pragma once
#include"Date.h"
#pragma warning(disable : 4996)
class Room
{

	char* reservationName;
	int id;
	int numberBeds;
	bool isOccupied;
	Interval interval;
	bool isClosed;
	//void copyFrom(const Room&);
	//void free();

public:

	Room();
	void setId(const int);
	void setReservationName(const char*);
	void setNumberBeds(const int);
	void setInterval(const Interval);
	void setIsOccupied(const bool);
	void setIsClosed(const bool);
	~Room();


};
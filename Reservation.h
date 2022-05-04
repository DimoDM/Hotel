#pragma once
#include"Room.h"
#include"Date.h"
class Reservation : Room
{
	char* name;
	Interval interval;

public:

	Reservation();
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const Reservation&);

	~Reservation();
};

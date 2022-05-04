#pragma once
#include"Room.h"
#include"Date.h"
#pragma warning(disable : 4996)
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

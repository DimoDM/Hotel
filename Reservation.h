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
	Reservation(const Room&, const Interval&);
	Reservation(const int&, const Interval&);

	void setId(const size_t&);
	void setBeds(const size_t&);
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const Reservation&);

	const char* getName() const;

	~Reservation();
};

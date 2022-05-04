#include"Reservation.h"

Reservation::Reservation() : Room()
{
	setName("null");
}

void Reservation::setName(const char* name)
{
	if (name != nullptr || &this->name != &name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Reservation::setInterval(const Interval& interval)
{
	this->interval = interval;
}

bool Reservation::operator==(const Reservation& res)
{
	if (id == res.id && interval == res.interval) return true;
	return false;
}

Reservation::~Reservation()
{
	delete[] name;
}

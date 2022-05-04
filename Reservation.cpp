#include"Reservation.h"

Reservation::Reservation() : Room()
{
	setName("null");
}

Reservation::Reservation(const Room& room, const Interval& interval) : Room()
{
	setName("null");
	setId(room.id);
	//setBeds(room.numberBeds);
	setInterval(interval);
}

Reservation::Reservation(const int& id, const Interval& interval)
{
	setId(id);
	setName("null");
	setInterval(interval);
}

void Reservation::setId(const size_t& id)
{
	this->id = id;
}

void Reservation::setBeds(const size_t& beds)
{
	numberBeds = beds;
}

void Reservation::setName(const char* name)
{
	if (name != nullptr || &this->name != &name) {
		if(this->name == nullptr)delete[] this->name;
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

const char* Reservation::getName() const
{
	return name;
}

Reservation::~Reservation()
{
	delete[] name;
}

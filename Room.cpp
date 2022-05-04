#include "Room.h"
#include<cstring>

Room::Room()
{
	reservationName = nullptr;
	id = 0;
	numberBeds = 0;
	isOccupied = false;
	isClosed = true;
}

void Room::setId(const int id)
{
	if (id > 0) this->id = id;
}

void Room::setReservationName(const char* name)
{
	if (&reservationName != &name) {
		reservationName = new char[strlen(name) + 1];
		strcpy(reservationName, name);
	}
}

void Room::setNumberBeds(const int beds)
{
	if(beds > 0) numberBeds = beds;
}

void Room::setInterval(const Interval period)
{
	interval = period;
}

void Room::setIsOccupied(const bool isBusy)
{
	isOccupied = isBusy;
}

void Room::setIsClosed(const bool isClosed)
{
	this->isClosed = isClosed;
}

Room::~Room()
{
	delete[] reservationName;
}

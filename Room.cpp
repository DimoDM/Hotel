#include "Room.h"
#include<cstring>
#include<iostream>
using namespace std;

void Room::copyFrom(const Room& room)
{
	setReservationName(room.reservationName);
	setId(room.id);
	setNumberBeds(room.numberBeds);
	setIsOccupied(room.isOccupied);
	setInterval(room.interval);
	setIsClosed(room.isClosed);
}

void Room::free()
{
	delete[] reservationName;
}

Room::Room()
{
	reservationName = nullptr;
	id = 0;
	numberBeds = 0;
	isOccupied = false;
	isClosed = true;
}

Room::Room(const Room& room)
{
	copyFrom(room);
}

const Room& Room::operator=(const Room& room)
{
	if (this != &room) {
		free();
		copyFrom(room);
	}
	return *this;
}

void Room::setId(const int id)
{
	if (id > 0) this->id = id;
}

const int Room::getId() const
{
	return id;
}

void Room::setReservationName(const char* name)
{
	if (&reservationName != &name && name!= nullptr) {
		delete[] reservationName;
		reservationName = new char[strlen(name) + 1];
		strcpy(reservationName, name);
	}
}

void Room::setNumberBeds(const int beds)
{
	if(beds > 0) numberBeds = beds;
}

const int Room::getNumberBeds() const
{
	return numberBeds;
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
	free();
}

const std::fstream& operator>>(std::fstream& stream, Room& room)
{
	int value;
	stream >> value;
	room.setId(value);
	stream.get();
	stream >> value;
	room.setNumberBeds(value);
	return stream;
}

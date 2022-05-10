#include "Room.h"
#include<cstring>
#include<iostream>
using namespace std;

Room::Room(size_t id = 0, size_t numberBeds = 0)
{
	this->id = id;
	this->numberBeds = numberBeds;
}

const std::fstream& operator>>(std::fstream& stream, Room& room)
{
	stream >> room.id;
	stream.get();
	stream >> room.numberBeds;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Room& room)
{
	stream << "Room " << room.id << " with " << room.numberBeds << " beds";
	return stream;
}

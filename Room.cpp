#include "Room.h"
#include<cstring>
#include<iostream>
using namespace std;


Room::Room()
{
	id = 0;
	numberBeds = 0;
	isClosed = true;
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

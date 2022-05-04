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

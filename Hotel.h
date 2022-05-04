#pragma once
#include"Room.h"

class Hotel
{
	Room rooms[20];

public:

	void regGuest();
	void showFreeRooms();
	void freeRoom();
	void occupiedReport();
	void searchRoom(const int, const Interval);
	void closeRoom();
};

#pragma once
#include"Room.h"
#include<fstream>
#include<iostream>
#include<string.h>
#include"Vector.h"
using namespace std;

class Hotel
{
	Vector<Room> rooms;
	std::fstream roomsFile;
	//Date currentDate;

public:

	Hotel();
	void getNumOfRooms() {
		cout << rooms.getSize() << endl;
		for (int i = 0; i < rooms.getSize(); i++) {
			cout << i << " " << rooms[i].getId() << " " << rooms[i].getNumberBeds()<<endl;
			//system("pause");
		}

	}
	//Hotel(const char*);

	void regGuest(); // make reservation for room
	//void showFreeRooms(); // show free rooms for a date
	//void freeRoom(); // make room free
	//void occupiedReport();
	void searchRoom(const int, const Interval);
	//void closeRoom();
};

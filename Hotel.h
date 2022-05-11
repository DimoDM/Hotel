#pragma once
#include"Room.h"
#include"RoomList.h"
#include"Interval.h"
#include"ClosedRoom.h"
#include<fstream>
#include<iostream>
#include"String.h"
#include"Vector.h"
using namespace std;

class Hotel
{
	Vector<Room> rooms;
	RoomList<ReservedRoom> resList;
	RoomList<ClosedRoom> clList;
	std::fstream roomsFile;
	Date currentDate;
	bool isRunning;

	int isValidRoomId(const int&);
	void makeRegistration(const char* name, const Date& date);
	void makeRegistration();
	void makeReservation();


public:

	Hotel();

	void update();

	void getNumOfRooms() {
		cout << rooms.getSize() << endl;
		for (int i = 0; i < rooms.getSize(); i++) {
			cout << i << " " << rooms[i].id << " " << rooms[i].numberBeds<<endl;
			//system("pause");
		}

	}
	//Hotel(const char*);

	void regGuest(); // make reservation for room
	void makeReport(); //make txt file for room's busyness
	void showFreeRooms(); // show free rooms for a date
	void freeRoom(); // make room free
	//void occupiedReport();

	void searchRoom();
	const Room& searchRoom(const int, const Interval);
	void closeRoom();


	const bool getIsRunning();
};

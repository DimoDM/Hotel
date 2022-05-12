#pragma once
#include"Room.h"
#include"../Structures/RoomList.h"
#include"Interval.h"
#include"ClosedRoom.h"
#include<fstream>
#include<iostream>
#include"String.h"
#include"../Structures/Vector.h"
using namespace std;

static Date currentDate = Date();

class Hotel
{
	Vector<Room> rooms;
	RoomList<ReservedRoom> resList;
	RoomList<ClosedRoom> clList;

	//std::fstream roomsFile;
	String fileName;
	bool isRunning;

	void loadValidRooms(ifstream&);
	int isValidRoomId(const int&);
	void makeRegistration(const char* name, const Date& date);
	void makeRegistration();
	void makeReservation();
	const Room& searchRoom(const int, const Interval);
	void init();


public:

	Hotel();
	Hotel(const char*);
	const String& getFileName() const;

	void regGuest(); // make reservation for room
	void makeReport(); //make txt file for room's busyness
	void showFreeRooms(); // show free rooms for a date
	void freeRoom(); // make room free
	void searchRoom();
	void closeRoom();

};

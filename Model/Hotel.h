#pragma once
#include"Room.h"
#include"../Structures/RoomList.h"
#include"Interval.h"
#include"ClosedRoom.h"
#include<fstream>
#include<iostream>
#include"../Structures/String.h"
#include"../Structures/Vector.h"
using namespace std;

class Hotel
{

	Vector<Room> rooms;
	RoomList<ReservedRoom> resList;
	RoomList<ClosedRoom> clList;

	String fileName;

	void loadValidRooms(ifstream&);
	int getRoomIndex(const int&);
	bool isValidRoomId(const int&);
	void makeRegistration(const char* name, const Date& date); // register guest. works with file and it will be better to be some kind of repository db class function
	void makeReservation(); // enter parameters for makeRegistration(), from the console, and calls it
	void findRoom(int, const Interval&); //show us free room with minimum beds in interval


public:

	Hotel();
	Hotel(const char*);
	const String& getFileName() const;
	Date currentDate;
	void init(); // initalize hotel. It's requred to be called outside of class.

	void regGuest(); // make reservation for room
	void makeReport(); //make txt file for room's busyness
	void showFreeRooms(); // show free rooms for a date
	void freeRoom(); // make room free
	void searchRoom(); // search for free room with minimum beds. Calls find room
	void closeRoom(); // close room

};

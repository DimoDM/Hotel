#pragma once
#include"Room.h"
#include"ReservationList.h"
#include<fstream>
#include<iostream>
#include<string.h>
#include"Vector.h"
using namespace std;

class Hotel
{
	Vector<Room> rooms;
	ReservationList resList;
	std::fstream roomsFile;
	Date currentDate;
	bool isRunning;

	int isValidRoomId(const int&);
	Date& enterDate(Date&);
	Date& enterDate();
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
	void searchRoom(const int, const Interval);
	//void closeRoom();


	const bool getIsRunning();
};

#pragma once
#include"Room.h"
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

class Hotel
{
	Room rooms[20];
	std::fstream roomsFile;
	//Date currentDate;

public:

	Hotel();
	void getNumOfRooms() {/*
		//getline(roomsFile);
		int i = 0;
		int id;
		int beds;
		while (!roomsFile.eof()) {
			roomsFile >> id;
			roomsFile >> beds;
			std::cout << id << " " << beds << std::endl;
			rooms[i].setNumberBeds(beds);
			rooms[i].setId(id);
			
			i++;
		}
		std::cout << i;*/

		int curPos = roomsFile.tellg();

	}
	//Hotel(const char*);

	void regGuest(); // make reservation for room
	//void showFreeRooms(); // show free rooms for a date
	//void freeRoom(); // make room free
	//void occupiedReport();
	void searchRoom(const int, const Interval);
	//void closeRoom();
};

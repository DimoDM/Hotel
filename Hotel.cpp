#include "Hotel.h"
#include<iostream>
#include <string>
using namespace std;

Hotel::Hotel()
{
	roomsFile.open("Rooms.csv");
	if (!roomsFile.is_open()) {
		perror("Can't open file");
		return;
	}
	string s;
	getline(roomsFile, s);
	getline(roomsFile, s);
	getline(roomsFile, s);
	getline(roomsFile, s);
	getline(roomsFile, s);
	int roomsInFloor;
	int floors;
	roomsFile >> roomsInFloor;
	roomsFile.get();
	roomsFile >> floors;
	cout << roomsInFloor << floors << endl;
	system("pause");
}

void Hotel::regGuest()
{

}

void Hotel::searchRoom(const int, const Interval)
{

}

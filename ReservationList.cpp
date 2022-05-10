#include "ReservationList.h"
#include<iostream>
using namespace std;
void ReservationList::saveChanges()
{
	file.seekp(0, std::ios::beg);
	for (int i = 0; i < data.getSize(); i++) {
		file << data[i];
	}
}
void ReservationList::getList()
{
		Reservation res;
		size_t val = getFileSize();
		file.seekg(0, std::ios::beg);
		while (file.tellg() < val) {
			file >> res;
			data.push_back(res);
		}
		file.close();
		file.open("resList.dat", ios::binary | ios::in | ios::out | ios::ate | ios::trunc);
		if (!file.is_open()) {
			perror("binary file error");
			exit(1);
		}
}
size_t ReservationList::getFileSize()
{
	size_t curPos = file.tellg();
	file.seekg(0, ios::end);
	size_t result = file.tellg();
	file.seekg(0, curPos);
	return result;
}
void ReservationList::printList()
{
	cout << data.getSize() << endl;
	for (int i = 0; i < data.getSize(); i++) {
		cout << data[i];
	}
}
ReservationList::ReservationList()
{
	fstream f("resList.dat", ios::binary | ios::app);
	f.close();
	file.open("resList.dat", ios::binary | ios::in | ios::out | ios::ate);
	file.seekg(0, ios::beg);
	if (!file.is_open()) {
		perror("binary file error");
		exit(1);
	}
	if (getFileSize() > 0) {
		getList();
	}
}


void ReservationList::addToList(const Room& room, const Interval& interval)
{
	Reservation res(room, interval);
	addToList(res);
	
}

void ReservationList::addToList(const Reservation& res)
{
	if (!isInList(res)) {
		data.push_back(res);
		saveChanges();
	}
	else cout << "room is not avaible :)" << endl;
}

bool ReservationList::isInList(const Room& room, const Interval& interval)
{
	Reservation res(room, interval);
	return isInList(res);
}

bool ReservationList::isInList(const Reservation& res)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (data[i] == res) return true;
	}
	return false;
}

ReservationList::~ReservationList()
{
	saveChanges();
	file.close();
}


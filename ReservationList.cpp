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
void ReservationList::loadList()
{
		ReservedRoom res;
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
		loadList();
	}
}

const size_t ReservationList::getDataSize() const
{
	return data.getSize();
}

Vector<ReservedRoom>& ReservationList::getData()
{
	return data;
}


void ReservationList::addToList(const Room& room, const Interval& interval)
{
	ReservedRoom res(room, interval);
	addToList(res);
	
}

void ReservationList::addToList(const ReservedRoom& res)
{
	if (!isInList(res)) {
		data.push_back(res);
		saveChanges();
	}
	else cout << "room is not avaible :)" << endl;
}

bool ReservationList::isInList(const Room& room, const Interval& interval)
{
	ReservedRoom res(room, interval);
	return isInList(res);
}

bool ReservationList::isInList(const ReservedRoom& res)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (data[i] == res) return true;
	}
	return false;
}

void ReservationList::removeFromList(const Room& room, const Interval& interval)
{
	ReservedRoom res(room, interval);
	removeFromList(res);
}

void ReservationList::removeFromList(const ReservedRoom& res)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (res == data[i]) {
			data[i] = data[data.getSize() - 1];
			/*
			for (int j = i; j < data.getSize() - 1; j++) {
				data[j] = data[j + 1];
			}*/
			data.pop_back();
			break;
		}
	}
}

void ReservationList::changeStayingPeriod(const Room room, const Date date)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (room.id == data[i].getId() && data[i].getInterval() == Interval(date, 0)) {
			Date newInterval = data[i].getInterval().getDate();
			size_t newPeriod = date - newInterval;
			if (newPeriod > 0) data[i].setInterval({ newInterval, date - newInterval });
			else data.pop_id(i);
			break;
		}
	}
}

ReservationList::~ReservationList()
{
	saveChanges();
	file.close();
}


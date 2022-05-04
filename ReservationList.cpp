#include "ReservationList.h"
#include<iostream>
using namespace std;
ReservationList::ReservationList()
{

	file.open("resList.dat", ios::binary | ios::in | ios::app | ios::out);
	if (!file.is_open()) {
		perror("binary file error");
		exit(1);
	}
	//id name interval
	Reservation res;
	size_t val;
	/*file.seekg(0, std::ios::beg);
	while (!file.eof()) {
		file.read((char*)&val, sizeof(size_t));
		res.setId(val);

		file.read((char*)&val, sizeof(size_t));
		const char* name = new char[val];
		file.read((char*)name, val);
		Interval interval;
		file.read((char*)&interval, sizeof(Interval));

		res.setName(name);
		res.setInterval(interval);
		data.push_back(res);
	}*/
	
	cout << data.getSize() << endl;
	for (int i = 0; i < data.getSize(); i++) {
		cout << data[i].getName();
	}
}

void ReservationList::addToList(const Room& room, const Interval& interval)
{
	Reservation res(room, interval);
	addToList(res);
}

void ReservationList::addToList(const Reservation& res)
{
	if (!isInList(res)) data.push_back(res);
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
	//file.close();
}

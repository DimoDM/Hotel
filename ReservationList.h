#pragma once
#include"Vector.h"
#include"Room.h"
#include"ReservedRoom.h"
#include"Interval.h"
#include<fstream>
#include<ostream>
#include<istream>
#include<iostream>
using namespace std;


template <typename T>
class ReservationList
{
	//source for limit T:
	//https://stackoverflow.com/questions/3175219/restrict-c-template-parameter-to-subclass
	static_assert(std::is_base_of<ReservedRoom, T>::value, "Derived not derived from BaseClass");

	Vector<T> data;
	std::fstream file;

	void saveChanges();
	void loadList();
	 size_t getFileSize() ;

public:

	ReservationList();
	const size_t getDataSize() const;
	Vector<T>& getData();
	void printList();
	//void addToList(const Room&, const Interval&);
	void addToList(const T&);
	//bool isInList(const Room&, const Interval&);
	bool isInList(const T&);
	//void removeFromList(const Room&, const Interval&);
	void removeFromList(const T&);
	void changeStayingPeriod(const Room, const Date);
	//void makeRaport(const Interval&);
	//void removeFromList(const Room&, const Interval&);

	//friend std::ostream& operator<<(std::ostream&, const ReservationList&);
	
	//~ReservationList();
};

template<typename T>
void ReservationList<T>::saveChanges()
{
	file.seekp(0, std::ios::beg);
	for (int i = 0; i < data.getSize(); i++) {
		file << data[i];
	}
}

template<typename T>
void ReservationList<T>::loadList()
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

template<typename T>
size_t ReservationList<T>::getFileSize()
{
	size_t curPos = file.tellg();
	file.seekg(0, ios::end);
	size_t result = file.tellg();
	file.seekg(0, curPos);
	return result;
}

template<typename T>
ReservationList<T>::ReservationList()
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

template<typename T>
const size_t ReservationList<T>::getDataSize() const
{
	return data.getSize();
}

template<typename T>
Vector<T>& ReservationList<T>::getData()
{
	return data;
}

template<typename T>
void ReservationList<T>::printList()
{
	cout << data.getSize() << endl;
	for (int i = 0; i < data.getSize(); i++) {
		cout << data[i];
	}
}

template<typename T>
void ReservationList<T>::addToList(const T& t)
{
	if (!isInList(t)) {
		data.push_back(t);
		saveChanges();
	}
	else cout << "room is not avaible :)" << endl;
}

template<typename T>
bool ReservationList<T>::isInList(const T& t)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (data[i] == t) return true;
	}
	return false;
}

template<typename T>
void ReservationList<T>::removeFromList(const T& t)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (t == data[i]) {
			data[i] = data[data.getSize() - 1];
			data.pop_back();
			break;
		}
	}
}

template<typename T>
void ReservationList<T>::changeStayingPeriod(const Room room, const Date date)
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



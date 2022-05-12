#pragma once
#include"Vector.h"
#include"../Model/Room.h"
#include"../Model/ReservedRoom.h"
#include"../Model/Interval.h"
#include<fstream>
#include<ostream>
#include<istream>
#include<iostream>
#include"FileManager.h"
using namespace std;

template <typename T>
class RoomList
{
	//source for limit T:
	//https://stackoverflow.com/questions/3175219/restrict-c-template-parameter-to-subclass
	static_assert(std::is_base_of<Room, T>::value, "Derived not derived from BaseClass");

	Vector<T> data;
	//std::fstream file;
	String fileName;

	void saveChanges();
	void loadList();
	void freeData();

public:
	RoomList() = default;
	RoomList(const char*);
	void setFileName(const char*);
	const size_t getDataSize() const;
	Vector<T>& getData();
	void printList();
	void addToList(const T&);
	bool isInList(const T&);
	void removeFromList(const T&);
	void changeStayingPeriod(const Room, const Date);
	//void makeRaport(const Interval&);
	//void removeFromList(const Room&, const Interval&);

	//friend std::ostream& operator<<(std::ostream&, const ReservationList&);
	
	//~ReservationList();
};

template<typename T>
void RoomList<T>::saveChanges()
{
	std::ofstream file;
	FileManager::openFile(file, fileName.c_str(), std::ios::binary | std::ios::trunc);
	for (int i = 0; i < data.getSize(); i++) {
		file << data[i];
	}
	file.close();
}

template<typename T>
void RoomList<T>::loadList()
{
	T t;
	std::ifstream file;
	FileManager::openFile(file, fileName.c_str(), std::ios::binary | std::ios::app);
	file.seekg(0, std::ios::beg);
	size_t val = FileManager::getFileSize(file);
	while (file.tellg() < val) {
		file >> t;
		data.push_back(t);
	}
	file.close();
}

template<typename T>
void RoomList<T>::freeData()
{
	while (data.getSize() != 0) data.pop_back();
}

template<typename T>
RoomList<T>::RoomList(const char* fileName)
{
	this->fileName = fileName;
	loadList();
}

template<typename T>
void RoomList<T>::setFileName(const char* name)
{
	fileName = name;
	freeData();
	loadList();
}

template<typename T>
const size_t RoomList<T>::getDataSize() const
{
	return data.getSize();
}

template<typename T>
Vector<T>& RoomList<T>::getData()
{
	return data;
}

template<typename T>
void RoomList<T>::printList()
{
	for (int i = 0; i < data.getSize(); i++) {
		cout << data[i];
	}
}

template<typename T>
void RoomList<T>::addToList(const T& t)
{
	if (!isInList(t)) {
		data.push_back(t);
		saveChanges();
	}
	else cout << "room is not avaible :)" << endl;
}

template<typename T>
bool RoomList<T>::isInList(const T& t)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (data[i] == t) return true;
	}
	return false;
}

template<typename T>
void RoomList<T>::removeFromList(const T& t)
{
	for (int i = 0; i < data.getSize(); i++) {
		if (t == data[i]) {
			data[i] = data[data.getSize() - 1];
			data.pop_back();
			break;
		}
	}
	saveChanges();
}

template<typename T>
void RoomList<T>::changeStayingPeriod(const Room room, const Date date)
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
	saveChanges();
}



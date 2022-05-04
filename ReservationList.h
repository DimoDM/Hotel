#pragma once
#include"Vector.h"
#include"Room.h"
#include<fstream>
class ReservationList
{

	Vector<Room> data;
	std::fstream file;

public:

	ReservationList();
	void addToList(const Room&, const Interval&);
	bool isInList(const Room&, const Interval&);
	void removeFromList(const Room&, const Interval&);

	~ReservationList();
};
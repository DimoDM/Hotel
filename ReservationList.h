#pragma once
#include"Vector.h"
#include"Room.h"
#include"Reservation.h"
#include<fstream>
class ReservationList
{

	Vector<Reservation> data;
	std::fstream file;

public:

	ReservationList();
	void addToList(const Room&, const Interval&);
	void addToList(const Reservation&);
	bool isInList(const Room&, const Interval&);
	bool isInList(const Reservation& res);
	//void removeFromList(const Room&, const Interval&);

	~ReservationList();
};
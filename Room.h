#pragma once
#include"Date.h"
#include<fstream>
#pragma warning(disable : 4996)
class Room
{

	char* reservationName;
	int id;
	int numberBeds;
	bool isOccupied;
	Interval interval;
	bool isClosed;

	void copyFrom(const Room&);
	void free();

public:

	Room();
	Room(const Room&);
	const Room& operator=(const Room&);
	void setId(const int);
	const int getId() const;
	void setReservationName(const char*);
	void setNumberBeds(const int);
	const int getNumberBeds() const;
	void setInterval(const Interval);
	void setIsOccupied(const bool);
	void setIsClosed(const bool);
	~Room();
};

const std::fstream& operator>>(std::fstream&, Room&);
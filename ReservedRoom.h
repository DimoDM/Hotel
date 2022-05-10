#pragma once
#include"Room.h"
#include"Date.h"
#include"Interval.h"
#include"String.h"
#pragma warning(disable : 4996)
class Reservation : private Room
{
	Interval interval;
	String name;

public:

	Reservation();
	Reservation(const Room& room, const Interval&);
	Reservation(const int& id, const Interval& interval);
	Reservation(const char* name, const int& id, const Interval& interval);

	void setId(const size_t&);
	void setBeds(const size_t&);
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const Reservation&) const;
	const Reservation& operator=(const Reservation&);

	const String getName() const;
	const size_t& getId() const;
	const Interval& getInterval() const;

	friend std::fstream& operator<<(std::fstream&, const Reservation&);
	friend std::fstream& operator>>(std::fstream&, Reservation&);
	friend std::ostream& operator<<(std::ostream&, const Reservation&);
	friend std::istream& operator>>(std::istream&, Reservation&);
};

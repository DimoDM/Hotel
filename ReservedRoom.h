#pragma once
#include"Room.h"
#include"Date.h"
#include"Interval.h"
#include"String.h"
#pragma warning(disable : 4996)
class ReservedRoom : private Room
{
	Interval interval;
	String name = "unknown";

public:

	ReservedRoom();
	ReservedRoom(const Room& room, const Interval&);
	ReservedRoom(const int id, const Interval& interval);
	ReservedRoom(const char* name, const int id, const Interval& interval);

	void setId(const size_t&);
	void setBeds(const size_t&);
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const ReservedRoom&) const;
	const ReservedRoom& operator=(const ReservedRoom&);

	const String getName() const;
	const size_t& getId() const;
	const Interval& getInterval() const;

	friend std::fstream& operator<<(std::fstream&, const ReservedRoom&);
	friend std::fstream& operator>>(std::fstream&, ReservedRoom&);
	friend std::ostream& operator<<(std::ostream&, const ReservedRoom&);
	friend std::istream& operator>>(std::istream&, ReservedRoom&);
};

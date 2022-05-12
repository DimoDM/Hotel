#pragma once
#include"Room.h"
#include"Date.h"
#include"Interval.h"
#include"../Structures/String.h"
#pragma warning(disable : 4996)
class ReservedRoom : private Room
{
	Interval interval;
	String name = "unknown";

public:

	ReservedRoom();
	ReservedRoom(const Room& room, const Interval&);
	ReservedRoom(const size_t id, const Interval& interval);
	ReservedRoom(const char* name, const size_t id, const Interval& interval);

	void init();
	void setId(const size_t&);
	void setBeds(const size_t&);
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const ReservedRoom&) const;
	const ReservedRoom& operator=(const ReservedRoom&);

	const String getName() const;
	const size_t& getId() const;
	const Interval& getInterval() const;

	friend std::ifstream& operator>>(std::ifstream&, ReservedRoom&);
};

std::ostream& operator<<(std::ostream&, const ReservedRoom&);
const std::istream& operator>>(const std::istream&, ReservedRoom&);
std::ofstream& operator<<(std::ofstream&, const ReservedRoom&);


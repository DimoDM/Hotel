#pragma once

#include"Room.h"
#include"Interval.h"

class ClosedRoom : private Room
{
	Interval interval;

public:

	ClosedRoom() = default;
	ClosedRoom(const size_t, const Interval&);

	void setId(const size_t);
	void setInterval(const Interval&);
	bool operator==(const ClosedRoom&) const;

	const size_t& getId() const;
	const Interval& getInterval() const;

	std::ifstream& readFile(std::ifstream&);
	std::ofstream& writeFile(std::ofstream&);
};

std::ostream& operator<<(std::ostream&, const ClosedRoom&);
const std::istream& operator>>(const std::istream&, ClosedRoom&);
std::ofstream& operator<<(std::ofstream&, const ClosedRoom&);

#pragma once
#include"Room.h"
#include"Date.h"
#include"Interval.h"
#pragma warning(disable : 4996)
class Reservation : public Room
{
	Interval interval;
	char* name;

	void copyName(const char*);
	void free();

public:

	Reservation();
	Reservation(const Room&, const Interval&);
	Reservation(const int& id, const Interval& interval);
	Reservation(const char* name, const int& id, const Interval& interval) : Reservation(id, interval) {
		copyName(name);
	}

	void setId(const size_t&);
	void setBeds(const size_t&);
	void setName(const char*);
	void setInterval(const Interval&);
	bool operator==(const Reservation&) const;
	const Reservation& operator=(const Reservation&);

	const char* getName() const;
	const size_t& getId() const;
	const Interval& getInterval() const;

	~Reservation();

	friend std::fstream& operator<<(std::fstream&, const Reservation&);
	friend std::fstream& operator>>(std::fstream&, Reservation&);
	friend std::ostream& operator<<(std::ostream&, const Reservation&);
	friend std::istream& operator>>(std::istream&, Reservation&);
};

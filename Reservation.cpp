#include"Reservation.h"
#include<iostream>

Reservation::Reservation() : Room()
{
	setName("null");
}

Reservation::Reservation(const Room& room, const Interval& interval) : Room()
{
	setName("null");
	setId(room.id);
	//setBeds(room.numberBeds);
	setInterval(interval);
}

Reservation::Reservation(const int& id, const Interval& interval)
{
	setId(id);
	setName("null");
	setInterval(interval);
}

void Reservation::setId(const size_t& id)
{
	this->id = id;
}

void Reservation::setBeds(const size_t& beds)
{
	numberBeds = beds;
}

void Reservation::setName(const char* name)
{
	if (name != nullptr || &this->name != &name) {
		if(this->name == nullptr)delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Reservation::setInterval(const Interval& interval)
{
	this->interval = interval;
}

bool Reservation::operator==(const Reservation& res)
{
	if (id == res.id && interval == res.interval) return true;
	return false;
}

const char* Reservation::getName() const
{
	return name;
}

const size_t& Reservation::getId() const 
{
	return id;
}

const Interval& Reservation::getInterval() const
{
	return interval;
}

Reservation::~Reservation()
{
	delete[] name;
}

std::fstream& operator<<(std::fstream& stream, const Reservation& res)
{
	size_t size = strlen(res.getName());
	stream.write((const char*)&res.getId(), sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write(res.getName(), strlen(res.getName()));
	stream.write((const char*)&res.getInterval(), sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, Reservation& res)
{
	size_t val;
	stream.read((char*)&val, sizeof(size_t));
	res.setId(val);

	stream.read((char*)&val, sizeof(size_t));
	char* name = new char[val];
	stream.read(name, val);
	name[val] = '\0';
	res.setName(name);
	//delete[] name;

	Interval interval;
	stream.read((char*)&interval, sizeof(Interval));
	res.setInterval(interval);

	return stream;
}

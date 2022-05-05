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

const size_t Reservation::getId() const 
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
	size_t id = res.getId();
	size_t size = strlen(res.getName());
	char* name = new char[size];
	Interval interval = res.getInterval();
	strcpy(name, res.getName());
	stream.write((const char*)&id, sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	std::cout << "size: " << size << std::endl;
	stream.write(name, size);
	stream.write((const char*)&interval, sizeof(Interval));
	return stream;
}

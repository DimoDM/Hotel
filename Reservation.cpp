#include"Reservation.h"
#include<iostream>

void Reservation::copyName(const char* name)
{
	size_t size = strlen(name);
	this->name = new char[size + 1];
	strcpy(this->name, name);
	this->name[size] = '\0';
}

void Reservation::free()
{
	delete[] name;
}

Reservation::Reservation() : Room()
{
	copyName("unknown");
}

Reservation::Reservation(const Room& room, const Interval& interval) : Room()
{
	copyName("unknown");
	setId(room.id);
	setInterval(interval);
}

Reservation::Reservation(const int& id, const Interval& interval)
{
	copyName("unknown");
	setId(id);
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
	size_t size = strlen(name);
	if (name != nullptr || &this->name != &name || size != 0) {
		if (this->name != nullptr) free();
		copyName(name);
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

const Reservation& Reservation::operator=(const Reservation& res)
{
	if (this != &res) {
		free();
		copyName(res.name);
		id = res.id;
		interval = res.interval;
	}
	return *this;
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
	free();
}

std::fstream& operator<<(std::fstream& stream, const Reservation& res)
{
	size_t size = strlen(res.name);
	stream.write((const char*)&res.id, sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write((const char*)res.name, size);
	stream.write((const char*)&res.interval, sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, Reservation& res)
{
	size_t val;
	stream.read((char*)&res.id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	if (res.name != nullptr) res.free();
	res.name = new char[val + 1];
	stream.read(res.name, val);
	res.name[val] = '\0';

	stream.read((char*)&res.interval, sizeof(Interval));
	return stream;
}

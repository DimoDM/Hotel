#include"Reservation.h"
#include<iostream>

Reservation::Reservation() : Room()
{
	name = "unknown";
}

Reservation::Reservation(const Room& room, const Interval& interval) : Room()
{
	name = "unknown";
	setId(room.id);
	setInterval(interval);
}

Reservation::Reservation(const int& id, const Interval& interval)
{
	name = "unknown";
	setId(id);
	setInterval(interval);
}

Reservation::Reservation(const char* name, const int& id, const Interval& interval)
{
	this->name = name;
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
	this->name = name;
}

void Reservation::setInterval(const Interval& interval)
{
	this->interval = interval;
}

bool Reservation::operator==(const Reservation& res) const
{
	if (id == res.id && interval == res.interval) return true;
	return false;
}

const Reservation& Reservation::operator=(const Reservation& res)
{
	if (this != &res) {
		name = res.name;
		id = res.id;
		interval = res.interval;
	}
	return *this;
}

const String Reservation::getName() const
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

std::fstream& operator<<(std::fstream& stream, const Reservation& res)
{
	size_t size = strlen(res.name.c_str());
	stream.write((const char*)&res.id, sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write((const char*)res.name.c_str(), size);
	stream.write((const char*)&res.interval, sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, Reservation& res)
{
	size_t val;
	stream.read((char*)&res.id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	char buff[1024];
	stream.read(buff, val);
	res.name = buff;

	stream.read((char*)&res.interval, sizeof(Interval));
	return stream;
}


std::ostream& operator<<(std::ostream& stream, const Reservation& res)
{
	stream << "client: " << res.getName() << " ,id of room: " << res.getId() << " ,Date: " << res.getInterval() << '\n';
	return stream;
}

const std::istream& operator>>(const std::istream& stream, Reservation& res)
{
	return stream;
}
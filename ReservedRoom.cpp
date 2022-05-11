#include"ReservedRoom.h"
#include<iostream>

ReservedRoom::ReservedRoom() : Room()
{
	name = "unknown";
}

ReservedRoom::ReservedRoom(const Room& room, const Interval& interval) : Room()
{
	name = "unknown";
	setId(room.id);
	setInterval(interval);
}

ReservedRoom::ReservedRoom(const int id, const Interval& interval)
{
	name = "unknown";
	setId(id);
	setInterval(interval);
}

ReservedRoom::ReservedRoom(const char* name, const int id, const Interval& interval)
{
	this->name = name;
	setId(id);
	setInterval(interval);
}

void ReservedRoom::setId(const size_t& id)
{
	this->id = id;
}

void ReservedRoom::setBeds(const size_t& beds)
{
	numberBeds = beds;
}

void ReservedRoom::setName(const char* name)
{
	this->name = name;
}

void ReservedRoom::setInterval(const Interval& interval)
{
	this->interval = interval;
}

bool ReservedRoom::operator==(const ReservedRoom& res) const
{
	if (id == res.id && interval == res.interval) return true;
	return false;
}

const ReservedRoom& ReservedRoom::operator=(const ReservedRoom& res)
{
	if (this != &res) {
		name = res.name;
		id = res.id;
		interval = res.interval;
	}
	return *this;
}

const String ReservedRoom::getName() const
{
	return name;
}

const size_t& ReservedRoom::getId() const 
{
	return id;
}

const Interval& ReservedRoom::getInterval() const
{
	return interval;
}

std::fstream& operator<<(std::fstream& stream, const ReservedRoom& res)
{
	size_t size = strlen(res.name.c_str());
	stream.write((const char*)&res.id, sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write((const char*)res.name.c_str(), size);
	stream.write((const char*)&res.interval, sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, ReservedRoom& res)
{
	size_t val;
	stream.read((char*)&res.id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	char buff[1024];
	stream.read(buff, val);
	buff[val] = '\0';
	res.name = buff;

	stream.read((char*)&res.interval, sizeof(Interval));
	return stream;
}


std::ostream& operator<<(std::ostream& stream, const ReservedRoom& res)
{
	stream << "client: " << res.getName() << " ,id of room: " << res.getId() << " ,Date: " << res.getInterval() << '\n';
	return stream;
}

const std::istream& operator>>(const std::istream& stream, ReservedRoom& res)
{
	return stream;
}
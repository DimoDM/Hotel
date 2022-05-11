#include"ClosedRoom.h"
#include<iostream>


void ClosedRoom::setId(const size_t& id)
{
	this->id = id;
}


void ClosedRoom::setInterval(const Interval& interval)
{
	this->interval = interval;
}

bool ClosedRoom::operator==(const ClosedRoom& room) const
{
	if (id == room.id && interval == room.interval) return true;
	return false;
}

const size_t& ClosedRoom::getId() const
{
	return id;
}

const Interval& ClosedRoom::getInterval() const
{
	return interval;
}

std::fstream& operator<<(std::fstream& stream, const ClosedRoom& room)
{
	stream.write((const char*)&room.id, sizeof(size_t));
	stream.write((const char*)&room.interval, sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, ClosedRoom& room)
{
	size_t val;
	stream.read((char*)&room.id, sizeof(size_t));
	stream.read((char*)&room.interval, sizeof(Interval));
	return stream;
}


std::ostream& operator<<(std::ostream& stream, const ClosedRoom& room)
{
	stream << "id of room: " << room.getId() << " ,Date: " << room.getInterval() << '\n';
	return stream;
}

const std::istream& operator>>(const std::istream& stream, ClosedRoom& res)
{
	return stream;
}
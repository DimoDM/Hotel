#include"ClosedRoom.h"
#include<iostream>


ClosedRoom::ClosedRoom(const size_t id, const Interval& interval)
{
	setId(id);
	setInterval(interval);
}

void ClosedRoom::setId(const size_t id)
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

std::ifstream& ClosedRoom::readFile(std::ifstream& stream)
{
	stream.read((char*)&this->id, sizeof(size_t));
	stream.read((char*)&this->interval, sizeof(Interval));
	return stream;
}

std::ofstream& ClosedRoom::writeFile(std::ofstream& stream) {
	stream.write((const char*)&this->getId(), sizeof(size_t));
	stream.write((const char*)&this->getInterval(), sizeof(Interval));
	return stream;
}

std::ofstream& operator<<(std::ofstream& stream, const ClosedRoom& room)
{
	stream << "id of room: " << room.getId() << " ," << room.getInterval() << '\n';
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const ClosedRoom& room)
{
	stream << "id of room: " << room.getId() << " ," << room.getInterval() << '\n';
	return stream;
}

const std::istream& operator>>(const std::istream& stream, ClosedRoom& res)
{
	return stream;
}
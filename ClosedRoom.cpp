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

bool ClosedRoom::operator==(const ClosedRoom& res) const
{
	if (id == res.id && interval == res.interval) return true;
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

std::fstream& operator<<(std::fstream& stream, const ClosedRoom& res)
{
	//size_t size = strlen(res.name.c_str());
	stream.write((const char*)&res.id, sizeof(size_t));
	//stream.write((const char*)&size, sizeof(size_t));
	//stream.write((const char*)res.name.c_str(), size);
	stream.write((const char*)&res.interval, sizeof(Interval));
	return stream;
}

std::fstream& operator>>(std::fstream& stream, ClosedRoom& res)
{
	size_t val;
	stream.read((char*)&res.id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	char buff[1024];
	stream.read(buff, val);
	buff[val] = '\0';
	//res.name = buff;

	stream.read((char*)&res.interval, sizeof(Interval));
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
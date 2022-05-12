#include"ReservedRoom.h"
#include<iostream>

ReservedRoom::ReservedRoom() : Room()
{
	name = GUESTNAME;
}

ReservedRoom::ReservedRoom(const Room& room, const Interval& interval) : ReservedRoom()
{
	setId(room.id);
	setInterval(interval);
}

ReservedRoom::ReservedRoom(const size_t id, const Interval& interval) : ReservedRoom()
{
	setId(id);
	setInterval(interval);
}

ReservedRoom::ReservedRoom(const char* name, const size_t id, const Interval& interval)
{
	this->name = name;
	setId(id);
	setInterval(interval);
}

void ReservedRoom::init()
{

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
	return id == res.id && interval == res.interval;
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

std::ofstream& operator<<(std::ofstream& stream, const ReservedRoom& res)
{
	size_t size = strlen(res.getName().c_str());
	stream.write((const char*)&res.getId(), sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write((const char*)res.getName().c_str(), size);
	stream.write((const char*)&res.getInterval(), sizeof(Interval));
	return stream;
}

std::ifstream& operator>>(std::ifstream& stream, ReservedRoom& res)
{
	size_t val;
	stream.read((char*)&res.id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	char buff[1024];
	stream.read(buff, val);
	buff[val] = '\0';
	res.setName(buff);

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
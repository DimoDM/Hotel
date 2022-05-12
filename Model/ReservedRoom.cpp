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

std::ofstream& ReservedRoom::writeFile(std::ofstream& stream)
{
	size_t size = strlen(this->getName().c_str());
	stream.write((const char*)&this->getId(), sizeof(size_t));
	stream.write((const char*)&size, sizeof(size_t));
	stream.write((const char*)this->getName().c_str(), size);
	stream.write((const char*)&this->getInterval(), sizeof(Interval));
	return stream;
}

std::ofstream& operator<<(std::ofstream& stream, const ReservedRoom& res)
{
	stream << "client: " << res.getName() << " ,id of room: " << res.getId() << " ," << res.getInterval() << std::endl;
	return stream;
}

std::ifstream& ReservedRoom::readFile(std::ifstream& stream)
{
	size_t val;
	stream.read((char*)&this->id, sizeof(size_t));
	stream.read((char*)&val, sizeof(size_t));

	char buff[1024];
	stream.read(buff, val);
	buff[val] = '\0';
	this->setName(buff);

	stream.read((char*)&this->interval, sizeof(Interval));
	return stream;
}

std::ifstream& operator>>(std::ifstream& stream, ReservedRoom& res)
{
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const ReservedRoom& res)
{
	stream << "client: " << res.getName() << " ,id of room: " << res.getId() << " ," << res.getInterval() << std::endl;
	return stream;
}

const std::istream& operator>>(const std::istream& stream, ReservedRoom& res)
{
	return stream;
}
#pragma once
#include"Date.h"
#include<fstream>
#include"Vector.h"
#pragma warning(disable : 4996)
struct Room
{
	Room(size_t id = 0, size_t numberBeds = 0);
	size_t id;
	size_t numberBeds;

};

const std::fstream& operator>>(std::fstream&, Room&);
std::ostream& operator<<(std::ostream&, const Room&);
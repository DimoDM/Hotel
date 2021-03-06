#pragma once
#include"Date.h"
#include<fstream>
#include"../Structures/Vector.h"
#pragma warning(disable : 4996)
struct Room
{
	Room(size_t id = 0, size_t numberBeds = 0);
	size_t id;
	size_t numberBeds;

};

const std::fstream& operator>>(std::fstream&, Room&);
const std::ifstream& operator>>(std::ifstream&, Room&);
std::ostream& operator<<(std::ostream&, const Room&);
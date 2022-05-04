#pragma once
#include"Date.h"
#include<fstream>
#include"Vector.h"
#pragma warning(disable : 4996)
struct Room
{
	Room();
	size_t id;
	size_t numberBeds;
	bool isClosed;

};

const std::fstream& operator>>(std::fstream&, Room&);
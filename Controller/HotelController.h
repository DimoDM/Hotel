#pragma once
#include"../Model/Hotel.h"
#include"../Structures/FileManager.h"
#include"String.h"
#include<iostream>
#include<fstream>
using namespace std;

class HotelController
{
	Hotel *hotel = nullptr;
	bool isRunning;
	Date currentDate;

	const char* FILELOG = "files/log.sys";
	void changeSettings();
	void saveSettings(ofstream&);
	void saveSettings();
	void loadSettings(ifstream&);
	void showOptions();
	void enterOption();

public:

	HotelController();
	void init();
	void update();
	const bool isStillRunning() const;

	~HotelController();

};
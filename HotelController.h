#pragma once
#include"Hotel.h"
#include"FileManager.h"
#include"String.h"
#include<iostream>
#include<fstream>
using namespace std;

class HotelController
{
	Hotel *hotel = nullptr;
	bool isRunning;

	const char* FILELOG = "log.dad";
	void changeSettings();
	void saveSettings(fstream&);
	void loadSettings(fstream&);
	void showOptions();
	void enterOption();

public:

	HotelController();
	void init();
	void update();
	const bool isStillRunning() const;

};
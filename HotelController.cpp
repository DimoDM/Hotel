#include "HotelController.h"
#include"cstring";

void HotelController::changeSettings()
{
	int choice;
	String roomFile = "";
	while (true) {
		cout << "Type 1 to use default settings and exit.\n"
			<< "Type 2 to manually enter current date.\n";
		if (!strcmp(roomFile.c_str(), "")) cout << "Type 3 to manually enter name for valid room's file(once set it cannot be changed)\n";
		cout << "Type 0 to exit this menu\n";

		cin >> choice;
		switch (choice) {
		case 1: hotel = new Hotel();
		case 0: if (!strcmp(roomFile.c_str(), "") && hotel == nullptr) hotel = new Hotel(roomFile.c_str()); return;
		case 2: Hotel::currentDate.init(); break;
		case 3: cout << "file name: ";
			cin >> roomFile; hotel = new Hotel(roomFile.c_str());
			break;
		default:cout << "Invalid input\n"; break;
		}
	}

}

void HotelController::saveSettings(fstream& file)
{
	if (!file.is_open()) {
		cout << "file is not open\n";
		return;
	}
	file.write((const char*)&Hotel::currentDate, sizeof(Date));
	size_t size = strlen(hotel->getFileName().c_str());
	file.write((const char*)&size, sizeof(size_t));
	file.write((const char*)hotel->getFileName().c_str(), size);
}

void HotelController::loadSettings(fstream& file)
{
	if (!file.is_open()) {
		cout << "file is not open\n";
		return;
	}
	file.read((char*)&Hotel::currentDate, sizeof(Date));
	size_t size;;
	file.read((char*)&size, sizeof(size_t));
	char* hName = new char[size];
	file.read(hName, size);
	if (hotel == nullptr) hotel = new Hotel(hName);
	delete[] hName;
}

HotelController::HotelController()
{
	init();
}

void HotelController::init()
{
	fstream file;
	FileManager::openFile(file, FILELOG, ios::binary | ios::app | ios::in | ios::out);
	if (FileManager::getFileSize(file) == 0) {
		cout << "This is your first log in, so you can set some settings.";
		changeSettings();
		if (hotel == nullptr) hotel = new Hotel();
		saveSettings(file);
	}
	else loadSettings(file);
	file.close();
}

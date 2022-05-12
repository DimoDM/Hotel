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
		case 0: if (strcmp(roomFile.c_str(), "") && hotel == nullptr) hotel = new Hotel(roomFile.c_str()); return;
		case 2: currentDate.init(); break;
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
	file.write((const char*)&currentDate, sizeof(Date));
	size_t size = strlen(hotel->getFileName().c_str());
	file.write((const char*)&size, sizeof(size_t));
	file.write((const char*)hotel->getFileName().c_str(), size);
}

void HotelController::saveSettings()
{
	fstream file;
	FileManager::openFile(file, FILELOG, ios::binary | ios::out | ios::trunc);
	saveSettings(file);
	file.close();
}

void HotelController::loadSettings(fstream& file)
{
	if (!file.is_open()) {
		cout << "file is not open\n";
		return;
	}
	file.read((char*)&currentDate, sizeof(Date));
	size_t size;;
	file.read((char*)&size, sizeof(size_t));
	char buff[1024];
	file.read((char*)&buff, size);
	buff[size] = '\0';
	if (hotel == nullptr) hotel = new Hotel(buff);
}

void HotelController::showOptions()
{
	cout << "Type 1 to register guest.\n"
		<< "Type 2 to see free rooms for date\n"
		<< "Type 3 to free room\n"
		<< "Type 4 to make report\n"
		<< "Type 5 to search for room\n"
		<< "Type 6 to close room\n"
		<< "Type 7 to change current date\n"
		<< "Type 0 to exit" << endl;
}

void HotelController::enterOption()
{
	int choice;
	cin >> choice;

	switch (choice) {
	case 0: isRunning = false; break;
	case 1: hotel->regGuest(); break;
	case 2: hotel->showFreeRooms(); break;
	case 3: hotel->freeRoom(); break;
	case 4: hotel->makeReport(); break;
	case 5: hotel->searchRoom(); break;
	case 6: hotel->closeRoom(); break;
	case 7: currentDate.init(); saveSettings(); hotel->currentDate = currentDate; break;
	default: cout << "Invalid input" << endl; break;
	}
}

HotelController::HotelController()
{
	isRunning = true;
	init();
}

void HotelController::init()
{
	fstream file;
	FileManager::openFile(file, FILELOG, ios::binary | ios::app | ios::in | ios::out);
	if (FileManager::getFileSize(file) == 0) {
		cout << "This is your first log in, so you can set some settings.\n";
		changeSettings();
		if (hotel == nullptr) hotel = new Hotel();
		saveSettings(file);
	}
	else loadSettings(file);
	file.close();
	hotel->currentDate = currentDate;
}

void HotelController::update()
{
	cout << "Current " << currentDate << endl << endl;
	showOptions();
	enterOption();
}

const bool HotelController::isStillRunning() const
{
	return isRunning;
}

HotelController::~HotelController()
{
	delete hotel;
}

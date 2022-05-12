#include "HotelController.h"
#include"cstring";

void HotelController::changeSettings()
{
	int choice;
	String roomFile = "";
	while (true) {
		cout << "Type 1 to use default settings and exit." << endl
			<< "Type 2 to manually enter current date." << endl;
		if (roomFile.getSize() == 0) cout << "Type 3 to manually enter name for valid room's file(once set it cannot be changed)" << endl;
		cout << "Type 0 to exit this menu" << endl;

		cin >> choice;
		switch (choice) {
		case 1: hotel = new Hotel();
		case 0: if (roomFile.getSize() == 0 && hotel == nullptr) hotel = new Hotel(roomFile.c_str()); return;
		case 2: currentDate.enter(); break;
		case 3: cout << "file name: ";
			cin >> roomFile; hotel = new Hotel(roomFile.c_str());
			break;
		default:cout << "Invalid input" << endl; break;
		}
	}

}

void HotelController::saveSettings(ofstream& file)
{
	if (!file.is_open()) {
		throw new exception("system file is not open");
	}
	file.write((const char*)&currentDate, sizeof(Date));
	size_t size = strlen(hotel->getFileName().c_str());
	file.write((const char*)&size, sizeof(size_t));
	file.write((const char*)hotel->getFileName().c_str(), size);
}

void HotelController::saveSettings()
{
	ofstream file;
	FileManager::openFile(file, FILELOG, ios::binary | ios::trunc);
	saveSettings(file);
	file.close();
}

void HotelController::loadSettings(ifstream& file)
{
	if (!file.is_open()) {
		throw new exception("system file is not open");
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
	cout << "Type 1 to register guest." << endl
		<< "Type 2 to see free rooms for date" << endl
		<< "Type 3 to free room" << endl
		<< "Type 4 to make report" << endl
		<< "Type 5 to search for room" << endl
		<< "Type 6 to close room" << endl
		<< "Type 7 to change current date" << endl
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
	case 7: currentDate.enter(); saveSettings(); hotel->currentDate = currentDate; break;
	default: cout << "Invalid input" << endl; break;
	}
}

HotelController::HotelController()
{
	isRunning = true;
}

void HotelController::init()
{
	ifstream file;
	FileManager::openFile(file, FILELOG, ios::binary | ios::app);
	if (FileManager::getFileSize(file) != 0) {
		loadSettings(file);
		file.close();
		hotel->init();
		hotel->currentDate = currentDate;
		return;
	}
	file.close();
	cout << "This is your first log in, so you can set some settings." << endl;
	changeSettings();
	if (hotel == nullptr) hotel = new Hotel();
	saveSettings();
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

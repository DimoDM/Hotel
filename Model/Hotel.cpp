#include "Hotel.h"
using namespace std;

void Hotel::loadValidRooms(ifstream& file)
{
	size_t fileSize = FileManager::getFileSize(file);
	if (fileSize <= 9) { //first line of file is with info for the table, so thiw if check if there is at least 1 element in the file
		cout << "Error! There are no rooms in the list or list is in incorrect format.";
		exit(1);
	}
	file.seekg(7, ios::beg);
	Room tempRoom;
	while (!file.eof()) {
		file >> tempRoom;
		rooms.push_back(tempRoom);
	}
	rooms.pop_back(); // strange behavior from eof couses last element to be saved twice
}

int Hotel::getRoomIndex(const int& id)
{
	for (int i = 0; i < rooms.getSize(); i++) {
		if (id == rooms[i].id) return i;
	}
	return rooms.getSize();
}

bool Hotel::isValidRoomId(const int& id) {
	return getRoomIndex(id) != rooms.getSize();
}

void Hotel::makeRegistration(const char* name, const Date& date)
{
	cout << "Enter period of staying in days: ";
	int period;
	cin >> period;
	cout << "Enter number of the room: ";
	size_t id;
	cin >> id;
	Interval interval(date, period);
	ReservedRoom res(name, id, interval);
	cout <<(bool) isValidRoomId(id) << endl;
	if (isValidRoomId(id)) {
		if (!clList.isInList({ id, interval })) resList.addToList(res);
		else cout << "There is no registered guest in the room, but no one can be accommodated in it.\n";
	}
	else cout << "There is no such room" << endl;
}

void Hotel::makeRegistration()
{
	makeRegistration("Guest", currentDate);
}

void Hotel::makeReservation()
{
	char name[1024];
	cout << "Enter name for reservation: ";
	cin >> name;
	Date date;
	cin >> date;
	makeRegistration(name, date);
}

Hotel::Hotel()
{
	fileName = "files/Rooms.csv";
}

Hotel::Hotel(const char* fileName)
{
	this->fileName = fileName;
}

const String& Hotel::getFileName() const
{
	return fileName;
}

void Hotel::init()
{
	std::ifstream file;
	FileManager::openFile(file, fileName.c_str());
	loadValidRooms(file);
	isRunning = true;
	file.close();

	// it's required to set file name one way or another
	resList.setFileName("files/resList.dat");
	clList.setFileName("files/closedRooms.dat");
}

void Hotel::regGuest()
{
	cout << "Type 0 to register now" << endl << "Type 1 to make reservation" << endl;
	bool choice;
	cin >> choice;
	if (choice) {
		makeReservation();
		resList.printList();
	}
	else {
		makeRegistration();
		resList.printList();
	}
}

void Hotel::makeReport()
{
	Interval interval;
	cin >> interval;
	String fileName("report");
	(((((fileName += interval.getDate().getYear()) += "-")
		+= interval.getDate().getMonth()) += "-")
		+= interval.getDate().getDay()) += ".txt";

	std::ofstream file(fileName.c_str(), std::ios::app);
	for (int i = 0; i < resList.getDataSize(); i++) {
		if (interval == resList.getData()[i].getInterval()) {
			file << resList.getData()[i];
			cout << resList.getData()[i];
		}
	}
	
}

void Hotel::showFreeRooms()
{
	Date date;
	cin >> date;
	Interval interval(date, 1);
	for (int i = 0; i < rooms.getSize(); i++)
		if (!resList.isInList({ rooms[i], interval })) {
			cout << rooms[i] << " is free for the entered day";
			if (clList.isInList({ rooms[i].id, interval })) cout << " but it is closed.";
			cout << endl;
		}

}

void Hotel::freeRoom()
{
	cout << "Enter id of room: ";
	int id;
	cin >> id;
	if (isValidRoomId(id)) {
		resList.changeStayingPeriod(Room(id), currentDate);
	}
	else cout << "Invalid id" << endl;
}

void Hotel::searchRoom()
{
	Interval interval;
	cin >> interval;
	cout << "Enter min number of beds: ";
	int beds;
	cin >> beds;
	findRoom(beds, interval);
}

void Hotel::findRoom(int beds, const Interval& interval)
{
	int currentMinBeds = -1;
	int id = 0;
	for (int i = rooms.getSize() - 1; i >= 0; i--) {
		if (currentMinBeds < beds && rooms[i].numberBeds >= beds) {
			currentMinBeds = rooms[i].numberBeds;
			id = i;
		}
		else if (currentMinBeds >= rooms[i].numberBeds 
			&& rooms[i].numberBeds >= beds 
			&& !resList.isInList(ReservedRoom(rooms[i], interval))
			&& !clList.isInList(ClosedRoom(rooms[i].id, interval))) {
			currentMinBeds = rooms[i].numberBeds;
			id = i;
		}
	}
	if (currentMinBeds == -1) cout << "We don't have free rooms with " << beds << " beds" << endl;
	else cout << rooms[id] << "is free" << endl;
}

void Hotel::closeRoom()
{
	size_t id;
	cout << "Enter number of the room: ";
	cin >> id;
	if (isValidRoomId(id)) {
		cout << "There is no such room" << endl;
		return;
	}

	Interval interval;
	cin >> interval;
	ClosedRoom room(id, interval);
	if (resList.isInList({ id, interval }))
		resList.changeStayingPeriod(id, interval.getDate());
	clList.addToList(room);
}
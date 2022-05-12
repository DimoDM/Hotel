#include "Hotel.h"
using namespace std;

void Hotel::loadValidRooms(ifstream& file)
{
	size_t fileSize = FileManager::getFileSize(file);
	if (fileSize <= 9) {
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

int Hotel::isValidRoomId(const int& id)
{
	for (int i = 0; i < rooms.getSize(); i++) {
		if (id == rooms[i].id) return i;
	}
	return 0;
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
	makeRegistration("unknown", currentDate);
}

void Hotel::makeReservation()
{
	char name[1024];
	cout << "Enter name for reservation: ";
	cin >> name;
	Date date;
	date.init();
	makeRegistration(name, date);
}

Hotel::Hotel()
{
	fileName = "files/Rooms.csv";
	init();
}

Hotel::Hotel(const char* fileName)
{
	this->fileName = fileName;
	init();
}

const String& Hotel::getFileName() const
{
	return fileName;
}

void Hotel::init()
{
	std::ifstream file;
	cout << fileName << endl;
	FileManager::openFile(file, fileName.c_str());
	loadValidRooms(file);
	isRunning = true;
	file.close();

	// it's required to set file name one way or another
	//var one
	resList.setFileName("files/resList.dat");
	clList.setFileName("files/closedRooms.dat");

	//var two
	/*
	resList = RoomList<ReservedRoom>("resList.dat");
	clList = RoomList<ClosedRoom>("closedRoom.dat");*/
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
	interval.init();
	String fileName("report");
	(((((fileName += interval.getDate().getYear()) += "-")
		+= interval.getDate().getMonth()) += "-")
		+= interval.getDate().getDay()) += ".txt";

	std::fstream file(fileName.c_str(), std::ios::out | std::ios::app);
	for (int i = 0; i < resList.getDataSize(); i++) {
		//TODO
		//fix == operation cuz I think don't work
		if (interval == resList.getData()[i].getInterval())
			file << resList.getData()[i];
	}
	
}

void Hotel::showFreeRooms()
{
	Date date;
	date.init();
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
	id = isValidRoomId(id);
	if (id != 0) {
		//resList.removeFromList(rooms[id], Interval(currentDate, 1));
		resList.changeStayingPeriod(rooms[id], currentDate);
	}
	else cout << "Invalid id" << endl;
}

void Hotel::searchRoom()
{
	Interval interval;
	interval.init();
	cout << "Enter min number of beds: ";
	int beds;
	cin >> beds;
	cout << searchRoom(beds, interval) << "is free" << endl;
}

const Room& Hotel::searchRoom(const int beds, const Interval interval)
{
	//TODO better
	int currentMinBeds = rooms[0].numberBeds > beds ? rooms[0].numberBeds : beds;
	int id = 0;
	for (int i = rooms.getSize() - 1; i >= 0; i--) {
		if (currentMinBeds >= rooms[i].numberBeds && rooms[i].numberBeds >= beds) {
			currentMinBeds = rooms[i].numberBeds;
			id = i;
		}
	}
	return rooms[id];
}

void Hotel::closeRoom()
{
	size_t id;
	cout << "Enter number of the room: ";
	cin >> id;
	Interval interval;
	interval.init();
	ClosedRoom room(id, interval);
	cout << (bool)isValidRoomId(id) << endl;
	if (isValidRoomId(id)) {
		if (resList.isInList({ id, interval }))
			resList.changeStayingPeriod(id, interval.getDate());
		clList.addToList(room);
	}
	else cout << "There is no such room" << endl;

}
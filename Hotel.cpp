#include "Hotel.h"
using namespace std;



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
	int id;
	cin >> id;
	ReservedRoom res(name, id, Interval(date, period));
	cout <<(bool) isValidRoomId(id) << endl;
	if (isValidRoomId(id)) resList.addToList(res);
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
	//resList.setFileName("newResList");
	clList.setFileName("closedRooms.dat");
	roomsFile.open("Rooms.csv");
	if (!roomsFile.is_open()) {
		perror("Can't open file");
		return;
	}
	roomsFile.seekg(7, ios::beg);
	Room tempRoom;
	while (!roomsFile.eof()) {
		roomsFile >> tempRoom;
		rooms.push_back(tempRoom);
	}
	rooms.pop_back(); // strange behavior from eof couses last element to be saved twice
	isRunning = true;
}

void Hotel::update()
{
	cout << "Type 1 to register guest.\n"
		<< "Type 2 to see free rooms for date\n"
		<< "Type 3 to free room\n"
		<< "Type 4 to make report\n"
		<< "Type 5 to search for room\n"
		<< "Type 6 to close room\n"
		<< "Type 0 to exit" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 0: isRunning = false; break;
	case 1: regGuest(); break;
	case 2: showFreeRooms(); break;
	case 3: freeRoom(); break;
	case 4: makeReport(); break;
	case 5: searchRoom(); break;
	case 6: closeRoom(); break;
	default: cout << "Invalid input" << endl; break;
	}
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
		if (!resList.isInList({ rooms[i], interval }))
			cout << rooms[i] << " is free for today" << endl;

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
	if (isValidRoomId(id)) clList.addToList(room);
	else cout << "There is no such room" << endl;

}

const bool Hotel::getIsRunning()
{
	return isRunning;
}

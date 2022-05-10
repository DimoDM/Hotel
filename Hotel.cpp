#include "Hotel.h"
using namespace std;



int Hotel::isValidRoomId(const int& id)
{
	for (int i = 0; i < rooms.getSize(); i++) {
		if (id == rooms[i].id) return i;
	}
	return 0;
}

Date& Hotel::enterDate(Date& date)
{
	cout << "enter YY/MM/DD with space between them: ";
	cin >> date.year >> date.mounth >> date.day;
	return date;
}

Date& Hotel::enterDate()
{
	Date date;
	return enterDate(date);
}

void Hotel::makeRegistration(const char* name, const Date& date)
{
	cout << "Enter period of staying in days: ";
	int period;
	cin >> period;
	cout << "Enter number of the room: ";
	int id;
	cin >> id;
	Reservation res(name, id, Interval(date, period));
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
	enterDate(date);
	makeRegistration(name, date);
}

Hotel::Hotel()
{
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
	case 4: searchRoom(); break;
	case 5: break;
	case 6: break;
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
	Date date;
	enterDate(date);
	cout << "Enter period of staying in days: ";
	int period;
	cin >> period;
	Interval interval(date, period);
	std::ofstream f("report.txt", std::ios::out | std::ios::app);
	
}

void Hotel::showFreeRooms()
{
	Interval interval(enterDate(), 1);
	for (int i = 0; i < rooms.getSize(); i++)
		if (!resList.isInList(rooms[i], interval))
			cout << rooms[i] << " is free for today" << endl;

}

void Hotel::freeRoom()
{
	cout << "Enter id of room: ";
	int id;
	cin >> id;
	id = isValidRoomId(id);
	if (id != 0) {
		resList.removeFromList(rooms[id], Interval(currentDate, 1));
	}
	else cout << "Invalid id" << endl;
}

void Hotel::searchRoom()
{
	//TODO make this better
	int period;
	cout << "Enter period :";
	cin >> period;
	Interval interval(enterDate(), period);
	cout << "Enter min number of beds: ";
	int beds;
	cin >> beds;
	cout << searchRoom(beds, interval) << "is free" << endl;
}

const Room& Hotel::searchRoom(const int beds, const Interval interval)
{
	int currentMinBeds = rooms[0].numberBeds > beds ? rooms[0].numberBeds : beds;
	int id = 0;
	for (int i = 0; i < rooms.getSize(); i++) {
		if (currentMinBeds >= rooms[i].numberBeds && rooms[i].numberBeds >= beds) {
			currentMinBeds = rooms[i].numberBeds;
			id = i;
		}
	}
	return rooms[id];
}

const bool Hotel::getIsRunning()
{
	return isRunning;
}

#include "Hotel.h"
using namespace std;



bool Hotel::isValidRoomId(const int& id)
{
	for (int i = 0; i < rooms.getSize(); i++) {
		if (id == rooms[i].id) return true;
	}
	return false;
}

Date& Hotel::enterDate(Date& date)
{
	cout << "enter YY/MM/DD with space between them: ";
	cin >> date.year >> date.mounth >> date.day;
	return date;
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
	case 0: break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	default: break;
	}
}

void Hotel::regGuest()
{
	cout << "type 0 to register now" << endl << "type 1 to make reservation" << endl;
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

void Hotel::searchRoom(const int, const Interval)
{

}

const bool Hotel::isRunning()
{
	return isRunning;
}

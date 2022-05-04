#include "Hotel.h"
using namespace std;



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

void Hotel::regGuest()
{
	cout << "type 0 to register now" << endl << "type 1 to make reservation" << endl;
	bool choice;
	cin >> choice;
	if (choice) {

	}
	else {
		cout << "Enter period of staying in days: ";
		int period;
		cin >> period;
		cout << "Enter number of the room: ";
		int id;
		cin >> id;

	}
}

void Hotel::searchRoom(const int, const Interval)
{

}

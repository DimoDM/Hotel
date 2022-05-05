#include<iostream>
#include"Hotel.h"
#include"Vector.h"

#include<map>
using namespace std;

int main()
{
	
	Hotel hotel;
	hotel.getNumOfRooms();
	while (true) {
		hotel.regGuest();
		cout << "continue?";
		bool s;
		cin >> s;
		if (!s) break;
	}
	system("pause");

}
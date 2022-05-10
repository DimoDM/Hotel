#include<iostream>
#include"Hotel.h"
#include"Vector.h"

#include<map>
using namespace std;

int main()
{
	
	Hotel hotel;
	//hotel.getNumOfRooms();
	while (hotel.isRunning()) {

		hotel.regGuest();

	}
	system("pause");

}
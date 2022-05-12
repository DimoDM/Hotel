#include<iostream>
#include"Controller/HotelController.h"
#include"Structures/Vector.h"
#include"UnitTests/UnitTests.h"
using namespace std;

int main()
{
	run();
	HotelController hotel;
	hotel.init();
	//hotel.getNumOfRooms();
	while (hotel.isStillRunning()) {

		hotel.update();

	}
	system("pause");

}
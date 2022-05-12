#include<iostream>
#include"Controller/HotelController.h"
#include"Structures/Vector.h"

using namespace std;

int main()
{
	
	HotelController hotel;
	//hotel.getNumOfRooms();
	while (hotel.isStillRunning()) {

		hotel.update();

	}
	system("pause");

}
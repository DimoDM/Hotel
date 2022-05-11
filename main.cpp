#include<iostream>
#include"HotelController.h"
#include"Vector.h"

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
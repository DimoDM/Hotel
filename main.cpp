#include<iostream>
#include"Controller/HotelController.h"
#include"UnitTests/UnitTests.h"
using namespace std;

int main()
{
	//run(); //start unit tests
	HotelController hotel;
	hotel.init();
	while (hotel.isStillRunning()) {

		hotel.update();

	}
}
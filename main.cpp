#include<iostream>
#include"Hotel.h"
#include"Vector.h"

#include<map>
using namespace std;

int main()
{
	
	Hotel hotel;

	while (hotel.getIsRunning()) {

		hotel.update();

	}
	system("pause");

}
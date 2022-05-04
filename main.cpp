#include<iostream>
#include"Hotel.h"
#include"Vector.h"
using namespace std;

int main()
{
	Hotel hotel;
	hotel.getNumOfRooms();

	Vector<int > a;
	a.push_back(2);
	a.push_back(3);
	cout << a.getSize() << a[1] << endl;
	a.push_back(2);
	a.push_back(3); 
	a.push_back(2);
	a.push_back(3); 
	a.push_back(2);
	a.push_back(3);
	cout << a.getSize() << a[1] << endl;

}
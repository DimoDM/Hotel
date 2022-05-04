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
	cout << a[1]<<endl;
	a[1] += 5;
	//cout << a[1]<<a.getSize()<<endl;
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	cout << a.getSize()<<endl;
	for (int i = 0; i < a.getSize(); i++) {
		cout <<i<<" "<< a[i] << endl;
	}
}
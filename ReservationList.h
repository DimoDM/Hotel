#pragma once
#include"Vector.h"
#include"Room.h"
#include"Reservation.h"
#include"Interval.h"
#include<fstream>
#include<ostream>
#include<istream>
class ReservationList
{

	Vector<Reservation> data;
	std::fstream file;

	void saveChanges();
	void getList();
	 size_t getFileSize() ;

public:

	ReservationList();
	const size_t getDataSize() const;
	Vector<Reservation>& getData();
	void printList();
	void addToList(const Room&, const Interval&);
	void addToList(const Reservation&);
	bool isInList(const Room&, const Interval&);
	bool isInList(const Reservation& res);
	void removeFromList(const Room&, const Interval&);
	void removeFromList(const Reservation& res);
	void makeRaport(const Interval&);
	//void removeFromList(const Room&, const Interval&);

	friend std::ostream& operator<<(std::ostream&, const ReservationList&);
	
	~ReservationList();
};
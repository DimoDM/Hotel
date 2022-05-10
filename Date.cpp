#include "Date.h"
#include<iostream>
#pragma once

void Date::nextDate(const int period)
{
	if (year % 4 == 0) numDaysInMounth[1] = 29;
	else numDaysInMounth[1] = 28;
	if (day + period > numDaysInMounth[mounth]) {
		int residue = period - (numDaysInMounth[mounth] - day);
		if (++mounth > 12) {
			mounth = 1;
			year++;
		}
		nextDate(residue);
	}
	else day += period;
}

Date::Date(int year, int mounth, int day)
{
	setYear(year);
	setMounth(mounth);
	setDay(day);
}

void Date::init()
{
	Date date;
	std::cout << "enter year: ";
	std::cin >> date.year;
	setYear(date.year);
	std::cout << "enter mounth: ";
	std::cin >> date.mounth;
	setMounth(date.mounth);
	std::cout << "enter day: ";
	std::cin >> date.day;
	setDay(date.day);
}

void Date::setYear(const int year)
{
	if (year >= 2022 || year <= 2023) this->year = year;
	else {
		std::cout << "Invalid year. Year 2022 was set\n";
		this->year = 2022;
	}
}

void Date::setMounth(const int mounth)
{
	if (mounth >= 1 || mounth <= 12) this->mounth = mounth;
	else {
		std::cout << "Invalid mounth. Mounth May set\n";
		this->mounth = 5;
	}
}

void Date::setDay(const int day)
{
	if (day >= 1 || day <= numDaysInMounth[mounth]) this->day = day;
	else {
		std::cout << "Invalid day. Day 1 set " << std::endl;
		this->day = 1;
	}
}

const int Date::getYear() const
{
	return year;
}

const int Date::getMounth() const
{
	return mounth;
}

const int Date::getDay() const
{
	return day;
}

const Date& Date::operator+=(const int period)
{
	nextDate(period);
	return *this;
}

const Date Date::operator+(const int period) const
{
	Date date = *this;
	date += period;
	return date;
}

bool Date::operator<(const Date date) const
{
	return year <= date.year && mounth <= date.mounth && day < date.day;
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	stream << "Date: " << date.getYear() << "/" << date.getMounth() << "/" << date.getDay();
	return stream;
}

#include "Date.h"
#include<iostream>
#include<math.h>
#pragma once

void Date::nextDate(const int period)
{
	if (year % 4 == 0) numDaysInMonth[1] = 29;
	else numDaysInMonth[1] = 28;
	if (day + period > numDaysInMonth[month - 1]) {
		int residue = period - (numDaysInMonth[month - 1]);
		if (++month > 12) {
			month = 1;
			year++;
		}
		nextDate(residue);
	}
	else day += period;
}

Date::Date(int year, int mounth, int day)
{
	setYear(year);
	setMonth(mounth);
	setDay(day);
}

void Date::init()
{
	Date date;
	std::cout << "enter year: ";
	std::cin >> date.year;
	setYear(date.year);
	std::cout << "enter mounth: ";
	std::cin >> date.month;
	setMonth(date.month);
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

void Date::setMonth(const int mounth)
{
	if (mounth >= 1 || mounth <= 12) this->month = mounth;
	else {
		std::cout << "Invalid mounth. Mounth May set\n";
		this->month = 5;
	}
}

void Date::setDay(const int day)
{
	if (day >= 1 || day <= numDaysInMonth[month]) this->day = day;
	else {
		std::cout << "Invalid day. Day 1 set " << std::endl;
		this->day = 1;
	}
}

const int Date::getYear() const
{
	return year;
}

const int Date::getMonth() const
{
	return month;
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

const bool Date::operator==(const Date date) const
{
	return year == date.year && month == date.month && day == date.day;
}

bool Date::operator<(const Date date) const
{
	return year <= date.year && month <= date.month && day < date.day;
}

const size_t Date::operator-(const Date date) const
{
	//TODO
	//can be improved
	Date curDate = *this;
	int period = 0;
	while (!(curDate == *this)) {
		curDate.nextDate(1);
		period++;
	}
	return period;
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	stream << "Date: " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay();
	return stream;
}

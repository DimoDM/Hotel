#include "Date.h"
#include<iostream>
#include<math.h>
#pragma once

void Date::nextDate(const int period)
{
	numDaysInMonth[1] = year % 4 == 0 ? 29 : 28;

	if (day + period <= numDaysInMonth[month - 1]) {
		day += period;
		return;
	}
	int residue = period - (numDaysInMonth[month - 1]);
	if (++month > 12) {
		month = 1;
		year++;
	}
	nextDate(residue);
}

Date::Date(int year, int mounth, int day)
{
	setYear(year);
	setMonth(mounth);
	setDay(day);
}

void Date::enter()
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

void Date::setYear(int year)
{
	if (year < 2021 || year > 2025) {
		std::cout << "Invalid year. Year 2022 was set\n";
		year = 2022;
	}
	this->year = year;
}

void Date::setMonth(int mounth)
{
	if (mounth < 1 || mounth > 12) {
		std::cout << "Invalid mounth. Mounth May set\n";
		month = 5;
	}
	this->month = mounth;
}

void Date::setDay(int day)
{
	if (day < 1 || day > numDaysInMonth[month]) {
		std::cout << "Invalid day. Day 1 set " << std::endl;
		day = 1;
	}
	this->day = day;
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

const size_t Date::operator-(Date date) const
{
	Date curDate = *this;
	if (date < curDate) {
		Date swap = date;
		date = curDate;
		curDate = swap;
	}
	int period = 0;
	while (!(curDate == date)) {
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

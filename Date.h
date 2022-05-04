#pragma once

struct Date
{
	int year = 2022;
	int mounth = 5;
	int day = 1;

	const Date& operator+=(const int period) {
		nextDate(period);
		return *this;
	}
	const Date operator+(const int period) const {
		Date date = *this;
		date += period;
		return date;
	}
	bool operator<(const Date date) const {
		if (year < date.year) return true;
		else if (year == date.year) {
			if (mounth < date.mounth) return true;
			else if (mounth == date.mounth) {
				if (day < date.day) return true;
				return false;
			}
			return false;
		}
		return false;
	}

private:
	int numDaysInMounth[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31 };
	void nextDate(const int period) {
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
};

struct Interval
{
	Date date;
	int periodInDays = 0;

	bool operator==(const Interval& interval) const {
		if (date < interval.date) {
			if ((date + periodInDays) < interval.date) return false;
			return true;
		}
		else if (interval.date < date) {
			if ((interval.date + periodInDays) < date) return false;
			return true;
		}
	}
	bool operator<(const Interval& interval) {
		if (date.year < interval.date.year) return true;
		else if (date.year == interval.date.year) {
			if (date.mounth < interval.date.mounth) return true;
			else if (date.mounth == interval.date.mounth) {
				if (date.day < interval.date.day) return true;
				return false;
			}
			return false;
		}
		return false;
	}
};
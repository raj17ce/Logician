#include "../include/Date.h"
#include "../include/String.h"
#include "../include/Exception.h"
using Exception::InvalidDateException;
using Utility::Date;
using Type::String;

String Date::computeStrDate() const {
	return (m_Day < 10 ? String{ "0" } : String{ "" }) + String::toString(m_Day) + String{ "/" } + (m_Month < 10 ? String{ "0" } : String{ "" }) + String::toString(m_Month) + String{ "/" } + String::toString(m_Year);
}
bool Date::isLeapYear(int yy) const {
	return (((yy % 4 == 0) && (yy % 100 != 0)) || (yy % 400 == 0));
}
bool Date::isDateValid(int dd, int mm, int yy) const {
	if (yy < 1) {
		throw InvalidDateException{ "Year " + String::toString(yy) + " is invalid" };
	};
	if (mm < 1 || mm > 12) {
		throw InvalidDateException{ "Month " + String::toString(mm) + " is invalid" };
	};
	if (dd < 1 || dd > 31) {
		throw InvalidDateException{ "Day " + String::toString(dd) + " is invalid" };
	};

	if (mm == 2) {
		if (isLeapYear(yy)) {
			if (dd > 29) throw InvalidDateException{ "Day " + String::toString(dd) + " is invalid" };
		}
		else {
			if(dd > 28) throw InvalidDateException{ "Day " + String::toString(dd) + " is invalid" };
		}
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		if(dd > 30) throw InvalidDateException{ "Day " + String::toString(dd) + " is invalid" };
	};

	return true;
}

void Date::setDay(int dd) {
	if (isDateValid(dd, m_Month, m_Year)) {
		m_Day = dd;
		m_IsCacheValid = false;
	}
}
void Date::setMonth(int mm) {
	if (isDateValid(m_Day, mm, m_Year)) {
		m_Month = mm;
		m_IsCacheValid = false;
	}
}
void Date::setYear(int yy) {
	if (isDateValid(m_Day, m_Month, yy)) {
		m_Year = yy;
		m_IsCacheValid = false;
	}
}
void Date::setDate(int dd, int mm, int yy) {
	if (isDateValid(dd, mm, yy)) {
		m_Day = dd;
		m_Month = mm;
		m_Year = yy;
	}
}
String Date::getStrDate() const {
	if (!m_IsCacheValid) {
		m_StrDate = computeStrDate();
		m_IsCacheValid = true;
	}
	return m_StrDate;
}

Date& Date::getCurrentDate() {
	static Date date{ 17,04,2003 };
	return date;
}
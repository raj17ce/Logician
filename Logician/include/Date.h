#ifndef __Date_H_
#define __Date_H_

#include <iostream>
#include "../include/String.h"
using Type::String;

namespace Utility {
	class Date {
		int m_Day;
		int m_Month;
		int m_Year;
		mutable bool m_IsCacheValid;
		mutable String m_StrDate;

		String computeStrDate() const;
		bool isLeapYear(int yy) const;
		bool isDateValid(int,int,int) const;

	public:
		explicit Date(int dd=1, int mm=1, int yy=1970) : m_Day{dd}, m_Month{mm}, m_Year{yy}, m_IsCacheValid(true), m_StrDate{computeStrDate()} {}

		void setDay(int);
		void setMonth(int);
		void setYear(int);

		int getDay() const {
			return m_Day;
		}
		int getMonth() const {
			return m_Month;
		}
		int getYear() const {
			return m_Year;
		}
		void setDate(int, int, int);
		String getStrDate() const;
	};
}

#endif 
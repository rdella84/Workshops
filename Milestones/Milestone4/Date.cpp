#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict {
	Date::Date() {
		m_dateOnly = false;
		set();
	}

	Date::Date(int year, int month, int day) {
		m_dateOnly = true;
		m_year = year;
		m_mon = month;
		m_day = day;
		m_hour = 0;
		m_min = 0;
		m_readErrorCode = NO_ERROR;
	}

	Date::Date(int year, int month, int day, int hour, int min) {
		m_dateOnly = false;
		m_year = year;
		m_mon = month;
		m_day = day;
		m_hour = hour;
		m_min = min;
		m_readErrorCode = NO_ERROR;
	}

	void Date::set() {
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		if (dateOnly()) {
			m_hour = m_min = 0;
		}
		else {
			m_hour = lt.tm_hour;
			m_min = lt.tm_min;
		}
	}

	int Date::value()const {
		return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		m_readErrorCode = errorCode;
	}

	void Date::set(int year, int mon, int day, int hour, int min) {
		m_readErrorCode = NO_ERROR;
		m_year = year;
		m_mon = mon;
		m_day = day;
		m_hour = hour;
		m_min = min;
	}

	bool Date::operator==(const Date& D)const {
		return this->value() == D.value();
	}
	bool Date::operator!=(const Date& D)const {
		return this->value() != D.value();
	}
	bool Date::operator<(const Date& D)const {
		return this->value() < D.value();
	}
	bool Date::operator>(const Date& D)const {
		return this->value() > D.value();
	}
	bool Date::operator<=(const Date& D)const {
		return this->value() <= D.value();
	}
	bool Date::operator>=(const Date& D)const {
		return this->value() >= D.value();
	}

	int Date::errCode()const {
		return m_readErrorCode;
	}

	bool Date::bad()const {
		return m_readErrorCode != NO_ERROR;
	}

	bool Date::dateOnly()const {
		return m_dateOnly;
	}

	void Date::dateOnly(bool value) {
		m_dateOnly = value;
		if (m_dateOnly == true) {
			m_hour = 0;
			m_min = 0;
		}
	}

	std::istream& Date::read(std::istream& istr) {
		char slash, colon, comma;
		m_readErrorCode = NO_ERROR;

		if (dateOnly()) {

			istr >> m_year;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR))
				m_readErrorCode = YEAR_ERROR;

			istr >> slash;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_mon;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_mon >= MIN_MON && m_mon <= MAX_MON))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = MON_ERROR;

			istr >> slash;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_day;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_day <= mdays() && m_day >= 1))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = DAY_ERROR;

		}

		else {
			istr >> m_year;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR))
				m_readErrorCode = YEAR_ERROR;

			istr >> slash;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_mon;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_mon >= MIN_MON && m_mon <= MAX_MON))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = MON_ERROR;

			istr >> slash;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_day;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_day <= mdays() && m_day >= 1))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = DAY_ERROR;

			istr >> comma;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_hour;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_hour >= MIN_HOUR && m_hour <= MAX_HOUR))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = HOUR_ERROR;

			istr >> colon;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;

			istr >> m_min;
			if (istr.fail())
				m_readErrorCode = CIN_FAILED;
			else if (!(m_min >= MIN_MIN && m_min <= MAX_MIN))
				if (m_readErrorCode == NO_ERROR)
					m_readErrorCode = MIN_ERROR;
		}
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr)const {
		if (m_dateOnly) {

			ostr << m_year;
			if (m_mon < 9)
				ostr << "/" << "0" << m_mon;
			else
				ostr << "/" << m_mon;
			if (m_day < 9)
				ostr << "/" << "0" << m_day;
			else
				ostr << "/" << m_day;

			
		}
		else {

			ostr << m_year;
			if (m_mon < 9)
				ostr << "/" << "0" << m_mon;
			else
				ostr << "/" << m_mon;
			if (m_day < 9)
				ostr << "/" << "0" << m_day;
			else
				ostr << "/" << m_day;
			if (m_hour < 9)
				ostr << ", " << "0" << m_hour;
			else
				ostr << ", " << m_hour;
			if (m_min < 9)
				ostr << ":" << "0" << m_min;
			else
				ostr << ":" << m_min;
		}
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Date& ct) {
		ct.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Date& cn) {
		cn.read(istr);
		return istr;
	}
}

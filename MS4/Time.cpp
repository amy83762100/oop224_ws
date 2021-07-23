/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/12  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min) {
		m_min = min;
	}
	ostream& Time::write(ostream& ostr) const {
		int hours;
		int minutes;
		if (m_min >= 0) {
			hours = m_min / 60;
			minutes = m_min % 60;
			ostr.fill('0');
			ostr.width(2);
			ostr << hours << ':';
			ostr.width(2);
			ostr << minutes;
		}
		return ostr;
	}
	istream& Time::read(istream& istr) {
		int hours;
		char c;
		int minutes;
		istr >> hours;
		istr >> c;
		istr >> minutes;
		if (!istr || c != ':' || hours < 0 || minutes < 0) istr.setstate(ios::failbit);
		else m_min = hours * 60 + minutes;
		return istr;
	}
	Time& Time::operator-= (const Time& D) {
		while (m_min < D.m_min)
		{
			m_min += (24 * 60);
		}
		m_min -= D.m_min;
		return *this;
	}
	Time Time::operator - (const Time & D)const {
		unsigned int min = m_min;
		while (min < D.m_min)
		{
			min += (24 * 60);
		}
		min -= D.m_min;
		return Time(min);
	}
	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D)const {
		int min = m_min;
		min += D.m_min;
		return Time(min);
	}
	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}
	Time& Time::operator *= (unsigned int val) {
		m_min *= val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const {
		int min = m_min;
		min *= val;
		return Time(min);
	}
	Time& Time::operator /= (unsigned int val) {
		m_min /= val;
		return *this;
	}
	Time Time::operator /(unsigned int val)const {
		int min = m_min;
		min /= val;
		return Time(min);
	}
	Time::operator int()const {
		return m_min;
	}
	Time::operator unsigned int()const {
		return m_min;
	}
	ostream& operator<<(ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}
}
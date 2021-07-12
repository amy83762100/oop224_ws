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
#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& ostr, IOAble& ioable) {
		ioable.write(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, IOAble& ioable) {
		ioable.read(istr);
		return istr;
	}
}
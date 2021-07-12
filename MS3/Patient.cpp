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
#include <string>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNumber, bool fileIO):m_ticket((ticketNumber)){
		m_fileIO = fileIO;
	}
	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}
	bool Patient::fileIO() const {
		return m_fileIO;
	}
	void Patient::fileIO(bool flag) {
		m_fileIO = flag;
	}
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}
	Patient::operator Time() const {
		return Time(m_ticket);
	}
	int Patient::number() const {
		return m_ticket.number();
	}
	bool operator==(const Patient& lp, const char& rc) {
		return lp.type() == rc;
	}
	bool operator==(const Patient& lp, const Patient& rp) {
		return lp.type() == rp.type();
	}
	ostream& Patient::csvWrite(ostream& ostr) const {
		ostr << type() << "," << m_name << "," << m_OHIPnumber << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	istream& Patient::csvRead(istream& istr) {
		m_name = getcstr("", istr, ',');
		istr >> m_OHIPnumber;
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;
	}
	ostream& Patient::write(ostream& ostr) const {
		m_ticket.write(ostr);
		ostr << endl;
		for (int i = 0; i < 25 && i < m_name[i] != '\0'; i++) ostr << m_name[i];
		return ostr	<< ", OHIP: " << m_OHIPnumber;
	}
	istream& Patient::read(istream& istr) {
		m_name = getcstr("Name: ", istr, '\n');
		m_OHIPnumber = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number,", true);
		return istr;
	}
}
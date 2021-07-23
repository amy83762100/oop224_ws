/* Citation and Sources...
Final Project Milestone 4
Module: Time
Filename: Time.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/23  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient() :Patient(nextTriageTicket) {
	   m_sympotoms = nullptr;
	   nextTriageTicket++;
   }
   char TriagePatient::type() const {
	   return 'T';
   }
   ostream& TriagePatient::csvWrite(ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   ostr << ',' << m_sympotoms;
	   return ostr;
   }
   istream& TriagePatient::csvRead(istream& istr) {
	   Patient::csvRead(istr);
	   istr.ignore(1,',');
	   string str;
	   getline(istr, str);
	   delete[] m_sympotoms;
	   m_sympotoms = new char[str.length() + 1];
	   strcpy(m_sympotoms, str.c_str());
	   // m_sympotoms = getcstr("", istr);
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }
   ostream& TriagePatient::write(ostream& ostr) const {
	   if (fileIO()) csvWrite(ostr);
	   else
	   {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: " << m_sympotoms << endl;
	   }
	   return ostr;
   }
   istream& TriagePatient::read(istream& istr) {
	   if (fileIO()) csvRead(istr);
	   else {
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   string str;
		   getline(istr, str);
		   delete[] m_sympotoms;
		   m_sympotoms = new char[str.length() + 1];
		   strcpy(m_sympotoms, str.c_str());
		   //m_sympotoms = getcstr("Symptoms: ", istr);
	   }
	   return istr;
   }
   TriagePatient::~TriagePatient() {
		   delete[] m_sympotoms;
		   m_sympotoms = nullptr;
   }
}
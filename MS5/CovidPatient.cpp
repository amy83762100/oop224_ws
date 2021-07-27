/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient():Patient(nextCovidTicket){
	   nextCovidTicket++;
   }
   char CovidPatient::type() const{
	   return 'C';
   }
   istream& CovidPatient::csvRead(istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   istr.ignore();
	   return istr;
   }
   ostream& CovidPatient::write(ostream& ostr) const {
	   if (fileIO()) Patient::csvWrite(ostr);
	   else
	   {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr.put('\n');
	   }
	   return ostr;
   }
   istream& CovidPatient::read(istream& istr) {
	   fileIO() ? csvRead(istr) : Patient::read(istr);
	   return istr;
   }
}
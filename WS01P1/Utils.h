// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// 
// Workshop 1:
// Version: 1.0
// Date: 2021/05/26
// Name: Pei-Yi Lin
// Email: plin24@myseneca.ca
// Student ID: 123423204
//
///////////////////////////////////////////////////
#ifndef UTILS_H 
#define UTILS_H 

// header file content 
namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}
#endif
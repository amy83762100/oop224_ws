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
#ifndef FILE_H 
#define FILE_H 

#include "ShoppingRec.h"

// header file content 
namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif
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
#ifndef SHOPPINGREC_H 
#define SHOPPINGREC_H 

// header file content 
#include "Utils.h"
namespace sdds {
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
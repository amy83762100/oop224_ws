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
#ifndef SHOPPINGLIST_H 
#define SHOPPINGLIST_H 

#include "File.h"

// header file content 
namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif
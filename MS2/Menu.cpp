/* Citation and Sources...
Final Project Milestone 2
Module: Time
Filename: Time.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/9  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		m_text = new char[strlen(MenuContent)+1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}
	Menu::~Menu(){
		delete[] m_text;
		m_text = nullptr;
	}
	Menu::Menu(const Menu& menu)
	{
		m_text = new char[strlen(menu.m_text) + 1];
		strcpy(m_text, menu.m_text);
		m_noOfSel = menu.m_noOfSel;
	}
	void Menu::display()const {
		cout << m_text << endl;
		cout << "0 - Exit" << endl;
	}
	int& Menu::operator>>(int& Selection) {
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
		return Selection;
	}
}
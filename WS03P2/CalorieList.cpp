#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
	void CalorieList::setEmpty() {
		m_items = nullptr;
	}
	bool CalorieList::isValid()const {
		bool valid = m_items != nullptr;
		if (valid) {
			for (int i = 0; i < m_noOfItems; i++) {
				valid = m_items[i].isValid();
				if (!valid) break;
			}
		}
		return valid;
	}
	int CalorieList::totalCalorie()const {
		int sum = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			sum += m_items[i].calorie();
		}
		return sum;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		cout << "| ";
		cout.width(50);
		cout.setf(ios::left);
		cout << (isValid() ? " Daily Calorie Consumption" : "Invalid Calorie Consumption list");
		cout << " |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today: ";
			cout.width(8);
			cout.setf(ios::right);
			cout << totalCalorie() << " |            |" << endl;
			cout.unsetf(ios::right);
		}
		else cout << "|    Invalid Calorie Consumption list                |" << endl;
		cout << "+----------------------------------------------------+" << endl;
	}
	void CalorieList::init(int noOfItems) {
		bool valid = noOfItems > 0;
		if (valid) {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}

	}
	bool CalorieList::add(const char* name, int calorie, int timeOfconsumption) {
		bool valid = m_itemsAdded < m_noOfItems;
		if (valid) {
			m_items[m_itemsAdded].set(name, calorie, timeOfconsumption);
			m_itemsAdded++;
		}
		return valid;
	}
	void CalorieList::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}
	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}
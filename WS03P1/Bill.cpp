#include <iostream>
#include "cstring.h"
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace sdds {
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid()const {
		bool valid = m_title[0] != '\0' && m_items != nullptr;
		if (valid) {
			for (int i = 0; i < m_noOfItems; i++) {
				valid = m_items[i].isValid();
			}
		}
		return valid;
	}
	double Bill::totalTax()const {
		double sum = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			sum += m_items[i].tax();
		}
		return sum;
	}
	double Bill::totalPrice()const {
		double sum = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			sum += m_items[i].price();
		}
		return sum;
	}
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		cout << "| ";
		cout.width(36);
		cout.setf(ios::left);
		cout << (isValid() ? m_title : "Invalid Bill ");
		cout << " |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << totalTax() + totalPrice() << " |" << endl;
			cout.unsetf(ios::right);
		}else cout << "| Invalid Bill                         |" << endl;
		cout << "+--------------------------------------+" << endl;
	}
	void Bill::init(const char* title, int noOfItems) {
		bool valid = title != nullptr && !noOfItems <= 0;
		if (valid) {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items= new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}

	}
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool valid = m_itemsAdded < m_noOfItems;
		if (valid) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
		}
		return valid;
	}
	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}
	void Bill::deallocate(){
		delete [] m_items;
		m_items = nullptr;
	}
}
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name) {
        strnCpy(m_itemName, name, 20);
    }
    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
    }
    void Item::set(const char* name, double price, bool taxed) {
        bool valid = price > 0 && name != nullptr;
        if (valid){ 
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
        else
            setEmpty();
    }
    double Item::price()const {
        return m_price;
    }
    double Item::tax()const {
        const double taxRate = 0.13;
        if (m_taxed) return m_price * 0.13;
        else return 0.0;
    }
    bool Item::isValid()const {
        return  m_itemName != nullptr && m_price > 0.0;
    }
    void Item::display()const {
        
        if (isValid()) {
            cout << "| ";
            cout.width(20);
            cout.setf(ios::left);
            cout.fill('.');
            cout << m_itemName;
            cout << " | ";
            cout.precision(2);
            cout.width(7);
            cout.setf(ios::fixed);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << m_price;
            cout << " | ";
            cout.width(3);
            cout.unsetf(ios::right);
            cout << (m_taxed ? "Yes" : "No");
            cout << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

}
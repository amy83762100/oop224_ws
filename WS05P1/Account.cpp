#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const {
       if (*this) {
           cout << " ";
           cout << m_number;
           cout << " | ";
           cout.width(12);
           cout.precision(2);
           cout.setf(ios::right);
           cout.setf(ios::fixed);
           cout << m_balance;
           cout.unsetf(ios::right);
           cout << " ";
       }
       else if (~*this) {
           cout << "  NEW  |         0.00 ";
       }
       else {
           cout << "  BAD  |    ACCOUNT   ";
       }
       return cout;
   }
   Account::operator bool() const {
       return m_number > 0 ? true : false;
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   bool Account::operator~() const{
       return  m_number == 0 ? true : false;
   }
   Account& Account::operator=(int number) {
       if (m_number == 0) m_number=number;
       return *this;
   }
   Account& Account::operator=(Account& acc) {
       if (m_number == 0 && acc.m_number > 0) {
           m_number = acc.m_number;
           m_balance = acc.m_balance;
           acc.m_number = 0;
           acc.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(double depositAmount) {
       if (m_number > 0 && depositAmount > 0) {
           m_balance += depositAmount;
       }
       return *this;
   }
   Account& Account::operator-=(double withdrawAmount) {
       if (m_number > 0 && withdrawAmount > 0 && withdrawAmount <= m_balance) {
           m_balance -= withdrawAmount;
       }
       return *this;
   }
   Account& Account::operator<<(Account& acc) {
       if (m_number > 0 && acc.m_number > 0 && m_number != acc.m_number) {
           m_balance += acc.m_balance;
           acc.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& acc) {
       if (m_number > 0 && acc.m_number > 0 && m_number != acc.m_number) {
           acc.m_balance += m_balance;
           m_balance = 0;
       }
       return *this;
   }
   double Account::operator+(const Account& acc) const {
       return (m_number > 0 && acc.m_number > 0) ? m_balance + acc.m_balance : 0;
   }
   double operator+=(double& sum, const Account& acc) {
       return sum+=acc.m_balance;
   }
}
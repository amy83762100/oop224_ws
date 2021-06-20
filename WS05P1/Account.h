#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(Account& acc);
      Account& operator+=(double depositAmount);
      Account& operator-=(double withdrawAmount);
      Account& operator<<(Account& acc);
      Account& operator>>(Account& acc);
      double operator+(const Account& acc) const;
      friend double operator+=(double& sum, const Account& acc);
   };
}
#endif // SDDS_ACCOUNT_H_
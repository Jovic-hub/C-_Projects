/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
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
      operator bool()const;
      operator int() const;
      operator double() const;
      bool operator~()const;
      Account& operator=(const int New);
      Account& operator=(Account& RO);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& RO);
      Account& operator>>(Account& RO);
   };

   double operator+(const Account& leftOper, const Account& rightOper);
   double operator+=(double& leftOper, const Account& rightOper);
   
   
}
#endif // SDDS_ACCOUNT_H_
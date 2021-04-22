/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
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

    Account::operator bool()const {
        return m_number > 0;
    }

    Account::operator int()const {
        return m_number;
    }

    Account::operator double()const {
        return m_balance;
    }

    bool Account:: operator~()const {
        return m_number == 0;
    }

    Account& Account::operator=(const int New) {
        if (~*this && m_number >= 10000 && m_number <= 99999 && m_balance > 0) {
            setEmpty();
        }
        else if (m_number == 0) {
          m_number = New;
        }
        return *this;
    }

    Account& Account::operator=(Account& RO) {
        if (~(*this) && RO) {
            m_balance = RO.m_balance, m_number = RO.m_number;
            RO.m_balance = 0, RO.m_number = 0;
        }
        return *this;
    }

    Account& Account::operator+=(double value) {
        if (*this && value > 0) {
            m_balance += value;
        }
        return *this;
    }

    Account& Account::operator-=(double value) {
        if (*this && value > 0 && m_balance > value) {
            m_balance -= value;
        }
        return *this;
    }

    Account& Account::operator<<(Account& RO) {
        if (this != &RO && *this && RO) {
            double sum = m_balance + RO.m_balance;
            m_balance = sum;
            RO.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& RO) {
        if (this != &RO && *this && RO) {
            double sum = RO.m_balance + m_balance;
            RO.m_balance = sum;
            m_balance = 0;
        }
        return *this;
    }

    double operator+(const Account& leftOper, const Account& rightOper) {
        if (bool(leftOper) && bool(rightOper)) {
            return double(leftOper) + double(rightOper);
        }
        else {
            return 0;
        }
    }

    double operator+=(double& leftOper, const Account& rightOper) {
        return leftOper += double(rightOper);
    }
}
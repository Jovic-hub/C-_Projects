/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
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
        m_taxed = true;
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (price > 0.0 && name != nullptr) {
            setName(name);
            m_price = price, m_taxed = taxed;
        }
        else {
            setEmpty();
        }
    }

    void Item::display()const {
        if (isValid()){
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(20);
            cout << m_itemName;
            cout.unsetf(ios::left);
            cout << " | ";
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.width(7);
            cout.fill(' ');
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::fixed);
            cout.unsetf(ios::right);
            cout << " | ";
            if (m_taxed == true)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No ";
            }
            cout << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
    bool Item::isValid()const {
        if (m_itemName[0] != '\0'){
            return true;
        }
        else {
            return false;
        }
    }

    double Item::price()const {
        return m_price;
    }

    double Item::tax()const {
        const double c_tax = 0.13;
        if (m_taxed == false) {
            return 0.0;
        }
        else {
           return m_price * c_tax;
        }
    }

}
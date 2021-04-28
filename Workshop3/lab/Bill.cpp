
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax()const {
        double tax = 0;
        for (int i = 0; i < m_noOfItems; i++) {
            tax += m_items[i].tax();
        }
        return tax;
    }

    double Bill::totalPrice()const {
        double price = 0;
        for (int i = 0; i < m_noOfItems; i++) {
            price += m_items[i].price();
        }
        return price;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout.unsetf(ios::left);
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.width(10);
            cout.precision(2);
            cout.fill(' ');
            cout << totalTax();
            cout << " |";
            cout << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout << totalPrice();
            cout << " |";
            cout << endl;
            cout << "|          Total After Tax: ";
            cout.setf(ios::right);
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |";
            cout << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid()const {
        bool valid = m_items != nullptr && m_title[0] != '\0';
        if (valid) {
            for (int i = 0; valid && i < m_noOfItems; i++) {
                valid = m_items[i].isValid();
            }
            return valid;      
        }
        else {
            return false;
        }
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title != nullptr && noOfItems > 0) {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems]();          
            for (int i = 0; i < noOfItems; i++) {
                m_items[i].setEmpty();
            }
           
        }
        else {
            setEmpty();
        }

    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded++].set(item_name, price, taxed);
            return true;
        }

        return false;

    }

    void Bill::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++){
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}

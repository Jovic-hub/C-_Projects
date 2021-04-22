/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

    double CalorieList::totalCalories()const {
        double calories = 0;
        for (int i = 0; i < m_noOfFoods; i++) {
            calories += m_items[i].calories();
        }
        return calories;
    }

    void CalorieList::Title()const {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid()) {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid()) {
            cout << "|    Total Calories for today:";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.width(9);
            cout.precision(0);
            cout.fill(' ');
            cout << totalCalories();
            cout << " |";
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.width(13);
            cout << " |";
            cout << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty() {
        m_items = nullptr;
    }

    bool CalorieList::isValid()const {
        bool valid = m_items != nullptr;
        if (valid) {
            for (int i = 0; valid && i < m_noOfFoods; i++) {
                valid = m_items[i].isValid();
            }
            return valid;
        }
        else {
            return false;
        }
    }

    void CalorieList::init(int size) {
        if (size > 0) {
            m_noOfFoods = size;
            m_itemsAdded = 0;
            m_items = new Food[m_noOfFoods]();
            for (int i = 0; i < size; i++) {
                m_items[i].setEmpty();
            }
        }
        else {
            setEmpty();
        }
    }

    bool CalorieList::add(const char* item_name, int calories, int when) {
        if (m_itemsAdded < m_noOfFoods) {
            m_items[m_itemsAdded++].set(item_name, calories, when);
            return true;
        }
        return false;

    }
    void CalorieList::display()const {
        Title();
        for (int i = 0; i < m_noOfFoods; i++) {
            m_items[i].display();
        }
        footer();
    }

    void CalorieList::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}
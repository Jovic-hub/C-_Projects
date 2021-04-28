
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {

    void Food::setName(const char* name) {
        strnCpy(m_itemName, name, 30);
    }

    void Food::setEmpty() {
        m_itemName[0] = '\0';
    }

    void Food::set(const char* name, int calories, int time) {

        if ((name != nullptr) && (time != 0 || time >= 5)) {
            setName(name);
            m_calories = calories, m_time = time;
        }
        else {
            setEmpty();
        }
    }

    void Food::display()const {
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(30);
            cout << m_itemName;
            cout << " |";
            cout.setf(ios::right);
            cout.fill(' ');
            cout.width(5);
            cout << m_calories;
            cout.unsetf(ios::right);
            cout << " | ";
            if (m_time == 1) {
                cout << "Breakfast";
                cout.setf(ios::right);
                cout.width(3);
                cout << " |";
                cout.unsetf(ios::right);
            }
            else if (m_time == 2) {
                cout << "Lunch";
                cout.setf(ios::right);
                cout.width(7);
                cout << " |";
                cout.unsetf(ios::right);
            }
            else if (m_time == 3) {
                cout << "Dinner";
                cout.setf(ios::right);
                cout.width(6);
                cout << " |";
                cout.unsetf(ios::right);
            }
            else if (m_time == 4) {
                cout << "Snack";
                cout.setf(ios::right);
                cout.width(7);
                cout << " |";
                cout.unsetf(ios::right);
            }
            cout << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;;
        }
    }

    double Food::calories()const {
        return m_calories;
    }

    bool Food::isValid()const {
        if (m_itemName[0] != '\0') {
            return true;
        }
        else {
            return false;
        }
    }

}

/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_value = 0;
    public:
        void isValid();
        Mark();
        Mark(int value);
        operator int()const;
        Mark& operator+=(int value);
        Mark& operator=(const Mark& value);
        operator double() const;
        operator char() const;
    };
    int operator+=(int& value, const Mark& right);
}
#endif 
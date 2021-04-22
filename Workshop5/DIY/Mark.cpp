/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
   
    Mark::Mark() {
        m_value = 0;
    }

    Mark::Mark(int grade) {
        m_value = grade;
        isValid();
    }

    void Mark::isValid() {
        if (m_value < 0 || m_value > 100) {
            m_value = -1;
        }
    }

    Mark::operator int()const {
        if (m_value >= 0) {
            return m_value;
        }
        return 0;
    }

    Mark& Mark::operator+=(int value) {
        if (m_value >= 0) {
            m_value += value;
            isValid();
        }
        return *this;
    }

    Mark& Mark:: operator=(const Mark& RightOp) { 
        m_value = RightOp.m_value;
        isValid();
        return *this; 
    }

    Mark::operator double()const {
        double GPA = 0;
        if (m_value >= 0 && m_value < 50) {
            GPA = 0;
        }
        else if (m_value >= 50 && m_value < 60) {
            GPA = 1;
        }
        else if (m_value >= 60 && m_value < 70) {
            GPA = 2;
        }
        else if (m_value >= 70 && m_value < 80) {
            GPA = 3;
        }
        else if (m_value >= 80 && m_value < 100) {
            GPA = 4;
        }
        return GPA;
    }

    Mark::operator char() const{
        char GPA = 'X';
        if (m_value >= 0 && m_value < 50) {
            GPA = 'F';
        }
        else if (m_value >= 50 && m_value < 60) {
            GPA = 'D';
        }
        else if (m_value >= 60 && m_value < 70) {
            GPA = 'C';
        }
        else if (m_value >= 70 && m_value < 80) {
            GPA = 'B';
        }
        else if (m_value >= 80 && m_value < 100) {
            GPA = 'A';
        }
        return GPA;
    }

    int operator+=(int& value, const Mark& right) {
        return value += int(right);
    }

}

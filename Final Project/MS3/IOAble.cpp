/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "IOAble.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, IOAble& D) {
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, IOAble& D) {
		return D.read(istr);
	}

}
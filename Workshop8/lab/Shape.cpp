/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, Shape& D) {
		D.draw(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& D) {
		D.getSpecs(istr);
		return istr;
	}
}
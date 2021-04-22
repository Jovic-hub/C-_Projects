/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream&) = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, Shape& D);
	std::istream& operator>>(std::istream& istr, Shape& D);
}

#endif
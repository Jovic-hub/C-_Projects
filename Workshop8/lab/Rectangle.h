/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "LblShape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H
namespace sdds {
	class Rectangle:public LblShape {
		int m_widht = 0;
		int m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* label, int widht, int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os);
	};
}

#endif
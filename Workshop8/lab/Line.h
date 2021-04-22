/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "LblShape.h"
#ifndef LINE_H
#define LINE_H
namespace sdds {
	class Line:public LblShape{
		int m_lenght = 0;
	public:
		Line();
		Line(const char* label, int lenght);
		void getSpecs(std::istream& is);	
		void draw(std::ostream& os);
	};
}

#endif
/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "Shape.h"
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
namespace sdds {
	class LblShape:public Shape {
		char* m_label = nullptr;
		LblShape(const LblShape&) = delete;
		void operator=(const LblShape&) = delete;
	public:
		const char* label()const;
		LblShape();
		LblShape(const char* label);
		~LblShape();
		void getSpecs(std::istream& is);
		void setLabel(const char* label);
	};
}

#endif
/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <iomanip>
#include "Rectangle.h"
#include <cstring>
using namespace std;
namespace sdds {
	Rectangle::Rectangle() {
		m_widht = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int widht, int height) :LblShape(label) {
		int a = (strlen(label) + 2);
		m_height = height;
		m_widht = widht;
		if (m_height < 3 || m_widht < a) {
			m_height = 0;
			m_widht = 0;
		}
	}
	void Rectangle::draw(std::ostream& os) {
		if (m_widht > 0 && m_height >> 0) {
			int size = m_widht - 2;
			os << "+";
			for (int i = 0; i < size; i++) {
				os << "-";
			}
			os << "+" << endl;

			os << "|" << label();
			int a = strlen(label());
			int b = size - a + 1;
			os << setw(b) << "|" << endl;

			int c = m_height - 3;
			for (int j = 0; j < c; j++) {
				os << "|";
				for (int i = 0; i < size; i++) {
					os << " ";
				}
				os << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < size; i++) {
				os << "-";
			}
			os << "+";
		}

	}
	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_widht;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}
}
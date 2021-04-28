
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() {
		m_lenght = 0;
	}
	Line::Line(const char* label, int lenght) :LblShape(label) {
		setLabel(label);
		m_lenght = lenght;
	}
	void Line::draw(std::ostream& os){
		if (m_lenght > 0 || label() != nullptr ){
			os << label() << endl;
			for (int i = 0; i < m_lenght; i++) {
				os << "=";
			}
		}
	}
	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_lenght;
		is.ignore(1000, '\n');
	}
}

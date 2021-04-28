
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

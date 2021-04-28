
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

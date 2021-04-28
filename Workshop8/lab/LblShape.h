
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

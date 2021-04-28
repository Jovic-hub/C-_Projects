
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

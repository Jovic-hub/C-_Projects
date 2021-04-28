
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, Shape& D) {
		D.draw(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& D) {
		D.getSpecs(istr);
		return istr;
	}
}

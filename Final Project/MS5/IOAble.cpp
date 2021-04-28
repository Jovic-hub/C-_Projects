#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "IOAble.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, IOAble& D) {
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, IOAble& D) {
		return D.read(istr);
	}

}

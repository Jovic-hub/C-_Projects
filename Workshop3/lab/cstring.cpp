
#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len; i++) {
			*des = *src;
			des++, src++;
		}
	}
}

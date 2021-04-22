#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		do {
			*des = *src;
			des++, src++;
		} while (*src != '\0');
		*des = '\0';
	}
	void strCat(char* des, const char* src) {
		do {
			des++;
		} while (*des != '\0');
		do {
			*des = *src;
			des++, src++;
		} while (*src != '\0');
		*des = '\0';
	}
	int strLen(const char* s) {
		int lenght = 0;
		for (int i = 0; s[i] > 0; i++) {
			lenght++;
		}

		return(lenght);
	}
}
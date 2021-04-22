/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include "cstring.h"
namespace sdds {
	int strCmp(const char* s1, const char* s2) {
		do {
			if (*s1 > *s2) {
				return 1;
			}
			else if (*s1 < *s2) {
				return -1;
			}
			s1++, s2++;
		} while ((*s1 != '\0') || (*s2 != '\0'));

		return 0;
	}

	int strLen(const char* s) {
		int lenght = 0;
		for (int i = 0; s[i] > 0; i++) {
			lenght++;
		}

		return(lenght);
	}

	void strCpy(char* des, const char* src) {
		do {
			*des = *src;
			des++, src++;
		} while (*src != '\0');
		*des = '\0';
	}
}
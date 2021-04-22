/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
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
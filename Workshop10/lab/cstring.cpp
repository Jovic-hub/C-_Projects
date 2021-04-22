/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds {

	void strCpy(char* des, const char* src) {
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

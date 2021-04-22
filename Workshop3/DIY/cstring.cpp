/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len; i++) {
			*des = *src;
			des++, src++;
		}
	}
}
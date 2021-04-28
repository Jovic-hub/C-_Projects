
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds {

	void strCpy(char *des, const char *src) {
		do {
			*des = *src;
			des++, src++;
		} while (*src != '\0');
		*des = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len; i++) {
			*des = *src;
			des++, src++;
		}
	}

	int strCmp(const char* s1, const char* s2) {
		do {
			if (*s1 > *s2){
				return 1; 
			}
			else if (*s1 < *s2) {
				return -1;
			}
			s1++, s2++;
		} while ((*s1 != '\0') || (*s2 != '\0'));

		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		do {
			if (*s1 > *s2) {
				return 1;
			}
			else if (*s1 < *s2) {
				return -1;
			}
			s1++, s2++, i++;
		} while (((*s1 != '\0') || (*s2 != '\0')) && i < len);

		return 0;
	}

	int strLen(const char* s) {
		int lenght = 0;
		for (int i = 0; s[i] > 0; i++) {
			lenght++;
		}

		return(lenght);
	}

	const char* strStr(const char* str1, const char* str2) {
		const char* string1, * string2;
		do {
			string1 = str1;
			string2 = str2;
			do {
				string1++, string2++;
			} while (*string2 && !(*string1 - *string2));
			if (!*string2) {
				return(str1);
			}
			str1++;
		} while (*str1);
		if (!*str2) {
			return(str1);
		}

		return NULL;
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

}

/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"
using namespace std;
namespace sdds {
	template <typename T, typename S>
	bool search(Collection<T>& CP, const T* ar, int number, S value);
	 //In the search, the requirements to work arein the main the function should be declared
	 //with 4 parameters, one reference from collection that we will use to compare with the key
	 //the array that we need to iterate 
	 //the total size of the array and the key that we will add in the CP.
	template <typename T, typename S>
	bool search(Collection<T>& CP, const T* ar, int number, S value) {
		bool isValid = false;
		int i = 0;
		while (i < number) { // while to loop until the i is less than the size of the array
			if (ar[i] == value) {
				CP.add(ar[i]); // adding the value found to the CP
				isValid = true;
			}
			i++;
		}
		return isValid;
	}

	template <typename T>
	void listArrayElements(const char* title, const T a[], int number);
	// In the list array Elements the requirements for my logic works are simple
	// the first parameter in the main should be a const char*, an array of size indetermined 
	// and the last parameter should have the size of the second parameter array
	template <typename T>
	void listArrayElements(const char* title, const T a[], int number){
		cout << title << endl; // printing title
		int i = 0;
		while(i < number) { // while to print everything 
			cout << i + 1 << ": " << a[i] << endl; // a[i] printing each index per time of the array.
			i++;
		}
	}

}
#endif
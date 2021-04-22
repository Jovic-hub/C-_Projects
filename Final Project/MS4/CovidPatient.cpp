/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CovidPatient.h"
using namespace std;
namespace sdds {
	int nextCovidTicket = 1;
	CovidPatient::CovidPatient():Patient(nextCovidTicket){
		nextCovidTicket++;
	}
	char CovidPatient::type()const {
		char C = 'C';
		return C;
	}
	std::istream& CovidPatient::csvRead(std::istream& istr) {
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		istr.ignore(1000, '\n');
		return istr;
	}
	std::ostream& CovidPatient::write(std::ostream& ostr)const {
		bool isValid = Patient::fileIO();
		if (isValid) {
			Patient::csvWrite(ostr);
		}
		else {
			ostr << "COVID TEST" << endl;
			Patient::write(ostr); 
			nextCovidTicket = Patient::number() + 1;
			ostr << endl;
		}
		return ostr;
	}
	std::istream& CovidPatient::read(std::istream& istr) {
		bool isValid = Patient::fileIO();
		if (isValid) {
			Patient::csvRead(istr);
		}
		else {
			Patient::read(istr);
		}
		return istr;
	}
}
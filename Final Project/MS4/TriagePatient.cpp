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
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient():Patient(nextTriageTicket) {
		m_symptoms = nullptr;
		nextTriageTicket++;
	}
	TriagePatient::~TriagePatient() {
		delete[]m_symptoms;
		m_symptoms = nullptr;
	}
	char TriagePatient::type()const {
		char T = 'T';
		return T;
	}
	std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {
		Patient::csvWrite(ostr);
		ostr << ",";
		ostr << m_symptoms;
		return ostr;
	}
	std::istream& TriagePatient::csvRead(std::istream& istr) {
		delete[]m_symptoms;
		m_symptoms = nullptr;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		char symptoms[1000];
		istr.getline(symptoms, 999, '\n');
		m_symptoms = new char[strlen(symptoms) + 1];
		strcpy(m_symptoms, symptoms);
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}
	std::ostream& TriagePatient::write(std::ostream& ostr)const {
		bool isValid = Patient::fileIO();
		if (isValid) {
			csvWrite(ostr);
		}
		else {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: " << m_symptoms << endl;
		}
		return ostr;
	}
	std::istream& TriagePatient::read(std::istream& istr) {
		bool isValid = Patient::fileIO();
		if (isValid) {
			csvRead(istr);
		}
		else {
			delete[]m_symptoms;
			m_symptoms = nullptr;
			Patient::read(istr);
			cout << "Symptoms: ";
			char symptoms[1000];
			istr.getline(symptoms, 999, '\n');
			m_symptoms = new char[strlen(symptoms) + 1];
			strcpy(m_symptoms, symptoms);
		}
		return istr;
	}
}
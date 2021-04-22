/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
#include "Patient.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds {
	Patient::Patient(int ticket, bool flag) {
		m_ticket = ticket;
		m_fileIO = flag;
	}
	Patient::~Patient() {
		delete[]m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO()const {
		return m_fileIO;
	}

	void Patient::fileIO(bool flag) {
		m_fileIO = flag;
	}

	bool Patient::operator==(const Patient& character)const {
		bool isValid = false;
		if (type() == character.type()) {
			isValid = true;
		}
		return isValid;
	}

	bool Patient::operator==(char character)const {
		bool isValid = false;
		if (character == type()) {
			isValid = true;
		}
		return isValid;
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	int Patient::number()const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << type() << ",";
		for (int i = 0; m_name[i] && i < 60; i++) {
			ostr << m_name[i];
		}
		ostr << "," << OHIP << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const {
		m_ticket.write(ostr);
		ostr << endl;
		for (int i = 0; m_name[i] && i < 25; i++) {
			ostr << m_name[i];
		}
		ostr << ", OHIP: " << OHIP;
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		char name[81];
		istr.getline(name, 80, ',');
		delete[]m_name;
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		istr >> OHIP;
		istr.ignore(1000, ',');
		m_ticket.csvRead(istr);
		return istr;
	}
	std::istream& Patient::read(std::istream& istr) {
		char name[81];
		cout << "Name: ";
		istr.getline(name, 80, '\n');
		delete[]m_name;
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		cout << "OHIP:";
		OHIP = getInt(100000000, 999999999, "", "Invalid OHIP Number, ");
		return istr;
	}

	Patient::operator Time()const {
		return Time(m_ticket);
	}
}

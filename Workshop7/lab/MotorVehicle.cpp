/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle() {
		m_plate[0] = {};
		m_address[0] = {};
		m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* plate, int year) {
		strCpy(this->m_address, "Factory");
		strCpy(this->m_plate, plate);
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		if (address != m_address) {
			cout << "|" << setw(8) << m_plate << "|";
			cout << " |" << setw(20) << m_address << " ---> ";
			cout.setf(ios::left);
			cout << setw(20) << address << "|";
			cout.unsetf(ios::left);
			cout << endl;
			strnCpy(m_address, address, 63);
			m_address[63] = char(0);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const {
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_plate;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& right) {
		return right.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& right) {
		return right.read(istr);
	}

}
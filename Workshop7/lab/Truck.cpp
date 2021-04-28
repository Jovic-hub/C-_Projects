
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Truck.h"
using namespace std;
namespace sdds {
	Truck::Truck(const char* plate, int year, double cargo, const char* address) :MotorVehicle(plate, year){
		m_capacity = cargo;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		bool isValid = false;
		if (m_cargo != m_capacity) {
			isValid = true;
			if (cargo < m_capacity) {
				m_cargo += cargo;
			}
			if (m_cargo > m_capacity) {
				m_cargo = m_capacity;
			}
		}
		return isValid;
	}

	bool Truck::unloadCargo() {
		bool unload = this->m_cargo > 0;
		m_cargo = 0;
		return unload;
	}

	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& right) {
		return right.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& right) {
		return right.read(istr);
	}
}

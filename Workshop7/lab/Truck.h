
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"
namespace sdds {
	class Truck:public MotorVehicle {
		double m_capacity = 0.0;
		double m_cargo = 0.0;
	public:
		Truck(const char* plate, int year, double cargo, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& right);
	std::istream& operator>>(std::istream& istr, Truck& right);
}
#endif

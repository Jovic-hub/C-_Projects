
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include <iostream>
namespace sdds {
	class MotorVehicle {
		char m_plate[9] = {};
		char m_address[64] = {};
		int m_year = 0;
	public:
		MotorVehicle();
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& text);
	std::istream& operator>>(std::istream& istr, MotorVehicle& text);
}
#endif


#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
	class TriagePatient :public Patient {
		char* m_symptoms = nullptr;
	public:
		TriagePatient();
		virtual char type()const;
		virtual std::ostream& csvWrite(std::ostream& ostr)const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H



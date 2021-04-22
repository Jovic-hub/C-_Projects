/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_PATIENT_TRIAGE_H_
#define SDDS_PATIENT_TRIAGE_H_
#include "Time.h"
#include "Patient.h"
#include "Menu.h"
namespace sdds {
	const int maxNoOfPatients = 100;
	class PreTriage {
		Time
			m_averCovidWait,
			m_averTriageWait;
		Patient* m_lineup[maxNoOfPatients]{};
		char* m_dataFilename = nullptr;
		int m_lineupSize = 0;
		Menu
			m_appMenu,
			m_pMenu;
		void reg();
		void admit();
		const Time getWaitTime(const Patient& p)const;
		void setAverageWaitTime(const Patient& p);
		void removePatientFromLineup(int index);
		int indexOfFirstInLine(char type) const;
		void load();
	public:
		PreTriage(const char* dataFilename);
		~PreTriage();
		void run(void);
	};

};
#endif
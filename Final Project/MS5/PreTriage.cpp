/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "PreTriage.h"
#include "Menu.h"
#include "Patient.h"
#include "utils.h"
#include "Ticket.h"
using namespace std;
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		delete[]m_dataFilename;
		m_dataFilename = nullptr;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		*m_lineup = nullptr;
		load();
	}
	PreTriage::~PreTriage() {
		ofstream file(m_dataFilename);
		cout << "Saving Average Wait Times," << endl << "   COVID Test: " << m_averCovidWait << endl << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		file << m_averCovidWait << "," << m_averTriageWait << endl;
		for (int i = 0; i < m_lineupSize; i++) {
			m_lineup[i]->csvWrite(file);
			file << endl;
			int a = i + 1;
			cout << a << "- ";
			m_lineup[i]->csvWrite(cout);
			cout << endl;
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}
		delete[]m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!" << endl;
	}
	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	int PreTriage::indexOfFirstInLine(char type) const {
		int isValid = -1;
		int i = 0;
		bool check = true;
		while (i < m_lineupSize && check) {
			if (*m_lineup[i] == type) {
				isValid = i;
				check = false;
			}
			i++;
		}
		return isValid;
	}
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int count = 0;

		for (int i = 0; i < maxNoOfPatients && m_lineup[i]; i++)
		{
			if (p.type() == m_lineup[i]->type())
			{
				Time() *= (int)m_lineup[i];
				count++;
			}

		}

		return Time();
	}
	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time time;
		time.setToNow();
		if (p.type() == 'C') {
			int Covid = 0;
			Covid = ((time - Time(p)) + (m_averCovidWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
			m_averCovidWait = Covid;
		}
		else if (p.type() == 'T') {
			int Triage = 0;
			Triage = ((time - Time(p)) + (m_averTriageWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
			m_averTriageWait = Triage;
		}
	}
	void PreTriage::load() {
		cout << "Loading data..." << endl;
		ifstream file(m_dataFilename);
		file >> m_averCovidWait;
		file.ignore();
		file >> m_averTriageWait;
		file.ignore(1000, '\n');

		Patient* p = nullptr;
		char patient;
		for (int i = 0; i < maxNoOfPatients && file; i++) {
			file >> patient;
			file.ignore();
			if (patient == 'C') {
				p = new CovidPatient();
			}
			else if (patient == 'T') {
				p = new TriagePatient();
			}
			if (p) {
				p->fileIO(true);
				file >> *p;
				m_lineup[i] = p;
				m_lineupSize++;
			}
		}
		if (file) {
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		}
		if (m_lineupSize > 0) {
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}
		else {
			cout << "No data or bad data file!" << endl<< endl;
		}
	}
	void PreTriage::reg() {
		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
			return;
		}
		int selection = 0;
		m_pMenu >> selection;
		if (selection == 1) {
			m_lineup[m_lineupSize] = new CovidPatient();
		}
		if (selection == 2) {
			m_lineup[m_lineupSize] = new TriagePatient();
		}
		if (selection == 0) {
			terminate();
		}
		m_lineup[m_lineupSize]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->fileIO(false);
		m_lineup[m_lineupSize]->read(cin);
		cout << endl << "******************************************" << endl;
		m_lineup[m_lineupSize]->write(cout);
		cout << "Estimated Wait Time: ";
		cout << getWaitTime(*m_lineup[m_lineupSize]);
		cout << endl << "******************************************" << endl << endl;
		m_lineupSize++;
	}
	void PreTriage::admit() {
		int selection = 0;
		m_pMenu >> selection;
		char type = 'a';
		if (selection == 1) {
			type = 'C';
		}
		if (selection == 2) {
			type = 'T';
		}
		if (selection == 0) {
			terminate();
		}
		int b = indexOfFirstInLine(type);
		if (b >= 1) {
			m_lineup[b]->fileIO(true);
		}
		cout << endl;
		cout << "******************************************" << endl;
		m_lineup[b]->fileIO(false);
		cout << "Calling for ";
		m_lineup[b]->write(cout);
		cout << "******************************************" << endl << endl;
		setAverageWaitTime(*m_lineup[b]);
		removePatientFromLineup(b);
	}
	void PreTriage::run(void) {
		int selection = 0;
		while (m_appMenu >> selection) {
			if (selection == 0) {
				terminate();
			}
			else if (selection == 1) {
				reg();
			}
			else if (selection == 2) {
				admit();
			}
		}
	}
}
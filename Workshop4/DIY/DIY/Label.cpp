/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "Label.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {

	bool Label::isEmpty()const {
		bool ok = false;
		if (m_conent == nullptr) {
			ok = true;
		}
		return ok;
	}
	Label::Label(){
		m_conent = nullptr;
		strCpy(m_frame, "+-+|+-+|");
	}
	Label::Label(const char* FrameArg) {
		m_conent = nullptr;
		strCpy(m_frame, FrameArg);
	}
	Label::Label(const char* frameArg, const char* content) {
		if (strlen(frameArg) == 8) {
			strCpy(m_frame, frameArg);
			m_conent = nullptr;
		}
		if (strlen(content) <= 71) {
			delete[] m_conent;
			int allocate = strLen(content);
			m_conent = new char[allocate + 1];
			strCpy(m_conent, content);
		}
	}

	void Label::readLabel() {
		char temp[71];
		cin.getline(temp, 71);
		if (cin.fail()) {
			cin.ignore(1000, '\n');
		}
		m_conent = new char[strlen(temp) + 1];
		strCpy(m_conent, temp);
	}

	std::ostream& Label::printLabel()const {
		if (!isEmpty()) {
			int len = strLen(m_conent);
			cout << m_frame[0];
			for (int i = 0; i < len + 2; i++) {
				cout << m_frame[1];
			}
			cout << m_frame[2];
			cout << endl;
			cout << m_frame[7];
			cout.width(len + 3);
			cout << m_frame[3] << endl;
			cout << m_frame[7] << " " << m_conent << " " << m_frame[3] << endl;
			cout << m_frame[7];
			cout.width(len + 3);
			cout << m_frame[3];
			cout << endl;
			cout << m_frame[6];
			for (int i = 0; i < len + 2; i++) {
				cout << m_frame[5];
			}
			cout << m_frame[4];
		}
		return cout;
	}

	Label::~Label() {
		delete[]m_conent;
		m_conent = nullptr;
	}

}

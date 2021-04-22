/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabels = noOfLabels;
		m_labels = new Label[noOfLabels];
	}
	void LabelMaker::readLabels() {
		cout << "Enter " << m_noOfLabels << " labels:";
		cout << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1;
			cout << endl;
			cout << "> ";
			m_labels[i].readLabel();
		}

	}
	void LabelMaker::printLabels() {
		for (int i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel(); 
			cout << endl;
		}
	}
	LabelMaker::~LabelMaker() {
		delete[] m_labels;
		m_labels = nullptr;
	}

}
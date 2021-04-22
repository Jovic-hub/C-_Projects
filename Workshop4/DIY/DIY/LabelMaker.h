/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_LABEL_MAKER_H
#define SDDS_LABEL_MAKER_H
#include <iostream>
#include "Label.h"
namespace sdds {
	class LabelMaker{
		Label* m_labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif
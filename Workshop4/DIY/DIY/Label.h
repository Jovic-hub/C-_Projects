/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
	class Label {
		char m_frame[9];
		char* m_conent;
		bool isEmpty()const;
	public:
		Label();
		Label(const char* FrameArg);
		Label(const char* frameArg, const char* content);
		void readLabel();
		~Label();
		std::ostream& printLabel() const;

	};
}
#endif
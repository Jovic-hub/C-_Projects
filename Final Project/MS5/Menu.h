/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu {
		char* m_text = nullptr;
		int m_noOfSel = 0;
		void display()const;
	public:
		Menu() {
			m_text = nullptr;
			m_noOfSel = 0;
		}
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);
		Menu& operator=(const Menu&) = delete;
	};
}
#endif
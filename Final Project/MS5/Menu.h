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

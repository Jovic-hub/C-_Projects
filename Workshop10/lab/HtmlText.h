/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title = nullptr;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& source);
      HtmlText& operator=(const HtmlText& source);
      ~HtmlText();
      void write(std::ostream& os)const;
   };
}
#endif 

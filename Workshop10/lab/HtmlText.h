
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

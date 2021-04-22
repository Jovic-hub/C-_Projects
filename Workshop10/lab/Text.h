/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
using namespace std;
namespace sdds {
   class Text {
      char* m_filename = nullptr;
      char* m_content = nullptr;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& text);
      Text& operator=(const Text& source);
      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text& right);
}
#endif 

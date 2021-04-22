/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include "cstring.h"
#include <string.h>
#include <fstream>
#include "Text.h"
using namespace std;
namespace sdds {
    const char& Text::operator[](int index)const {
        return m_content[index];
    }
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
   Text& Text::operator=(const Text& source) {
       if (this != &source) {
           if (source.m_content != nullptr) {
               delete[]m_content;
               m_content = nullptr;
               m_content = new char[strLen(source.m_content) + 1];
               strCpy(m_content, source.m_content);
           }
       }
       return *this;
   }
   Text::Text(const Text& text) {
       if (this != &text) {
           if (text.m_content != nullptr) {
               delete[]m_content;
               m_content = nullptr;
               m_content = new char[strLen(text.m_content) + 1];
               strCpy(m_content, text.m_content);
           }
       }
   }
   Text::~Text() {
       delete[]m_content;
       m_content = nullptr;
       delete[]m_filename;
       m_filename = nullptr;
   }
   Text::Text(const char* filename) {
       if (filename != nullptr) {
           delete[]m_filename;
           m_filename = nullptr;
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }
   void Text::read() {
       ifstream file(m_filename);
       string a;
       if (getFileLength() > 0) {
           delete[] m_content;
           m_content = nullptr;
           m_content = new char[getFileLength() + 1];
           getline(file, a, '\0');
           strCpy(m_content, a.c_str());
       }
   }
   void Text::write(std::ostream& os)const {
       if (m_content != nullptr) {
           os << m_content;
       }
   }
   std::ostream& operator<<(std::ostream& ostr, const Text& right) {
       right.write(ostr);
       return ostr;
   }

}
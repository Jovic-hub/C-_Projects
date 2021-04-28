
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "cstring.h"
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "HtmlText.h"
using namespace std;
namespace sdds {
    HtmlText::HtmlText(const char* filename, const char* title) :Text(filename) {
        if (title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& source) :Text(source) {
        if (source.m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[strLen(source.m_title) + 1];
            strCpy(m_title, source.m_title);
        }
    }

    HtmlText& HtmlText::operator=(const HtmlText& source) {
        Text::operator=(source);
        if (this != &source) {
            if (source.m_title != nullptr) {
                delete[] m_title;
                m_title = nullptr;
                m_title = new char[strLen(source.m_title) + 1];
                strCpy(m_title, source.m_title);
            }
        }
        return *this;
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;
    }
    void HtmlText::write(std::ostream& os)const{
        bool MS = false;
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        const HtmlText& T = *this;
        for (int i = 0; T[i]; i++) {
            if (T[i] == ' ') {
                if (MS) {
                    os << "&nbsp;";
                }
                else {
                    MS = true;
                    os << " ";
                }
            }
            if (T[i] == '<') {
                os << "&lt;";
                MS = false;
            }
            if (T[i] == '>') {
                os << "&gt;";
                MS = false;
            }
            if (T[i] == '\n') {
                os << "<br />\n";
                MS = false;
            }
            if (T[i] != '\n' && T[i] != '>' && T[i] != '<' && T[i] != ' ') {
                MS = false;
                os << T[i];
            }
        }
        os << "</body>\n</html>";
    }
}

/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow(){
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min) {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const {
        char column[] = ":";
        int HH = m_min / 60;
        int MM = m_min % 60;
        if (HH < 10) {
            ostr << 0 << HH;
        }
        else {
            ostr << HH;
        }
        ostr << column;
        if(MM < 10) {
            ostr << 0 << MM;
        }
        else {
            ostr << MM;
        }
        return ostr;
    }
    std::istream& Time::read(std::istream& istr) {
        int hour = 0;
        int minutes = 0;
        istr >> hour;
        if (hour < 0) {
            istr.setstate(ios::failbit);
        }
        if (istr.get() != ':') {
            istr.setstate(ios::failbit);
        }
        istr >> minutes;
        if (minutes < 0) {
            istr.setstate(ios::failbit);
        }
        if (istr) {
            m_min = (unsigned) minutes + hour * 60;
        }
        return istr;
    }
    Time& Time::operator-=(const Time& D) {
        if (m_min < D.m_min) {
            m_min += 1440;
        }
        if (D.m_min > 1440) {
            m_min += 1440;
        }
        m_min = m_min - D.m_min;
        return *this;
    }
    Time& Time::operator+=(const Time& D) {
        m_min = m_min + D.m_min;
        return *this;
    }
    Time Time::operator-(const Time& D)const {
        int min = m_min;
        int right = D.m_min;
        if (min < right) {
            min += 1440;
        }
        if (right > 1440) {
            min += 1440;
        }
        return Time(min - right);
    }
    Time Time::operator+(const Time& D)const {
        return Time(m_min + D.m_min);
    }
    Time& Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val) {
        m_min = m_min * val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val) {
        m_min = m_min / val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const {
        return Time(m_min * val);
    }
    Time Time::operator /(unsigned int val)const {
        return Time(m_min / val);
    }
    Time::operator unsigned int()const {
        return m_min;
    }
    Time::operator int()const {
        return int(m_min);
    }
    std::istream& operator>>(std::istream& istr, Time& D) {
        return D.read(istr);
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D) {
        return D.write(ostr);
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "Canister.h"
using namespace std;
namespace sdds {
    double PI = 3.14159265;

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_hieght = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    bool Canister::isEmpty()const {
        bool ok = false;
        if (m_contentVolume < 0.00001) {
            ok = true;
        }
        return ok;
    }

    bool Canister::hasSameContent(const Canister& C)const {
        bool ok = false;
        if (m_contentName != nullptr && C.m_contentName != nullptr && strCmp(m_contentName, C.m_contentName) == 0) {
            ok = true;
        }
        return ok;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable){
            delete[] m_contentName;
            int allocate = strLen(Cstr);
            m_contentName = new char[allocate + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double hieght, double diameter, const char* contentName) {
        setToDefault();
        if (hieght >= 10 && hieght <= 40 && diameter >= 10 && diameter <= 30) {
            m_hieght = hieght, m_diameter = diameter;      
            m_contentVolume = 0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }

    Canister::~Canister() {
        delete[]m_contentName;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        } else if(isEmpty()){
            setName(contentName);
        }
        else if (!hasSameContent(contentName)) {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && quantity + volume() <= capacity()) {
            m_contentVolume = quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName);
        if (C.m_contentVolume > (capacity() - volume())) {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    std::ostream& Canister::display()const {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity();
        cout << "cc (";
        cout << m_hieght;
        cout << "x";
        cout << m_diameter;
        cout << ") Canister";
        if (m_usable == false) { // name not null
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout << volume();
            cout << "cc   ";
            cout << m_contentName;
        }
        return cout;
    }

    double Canister::capacity()const {
        return PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear() {
        delete[]m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}

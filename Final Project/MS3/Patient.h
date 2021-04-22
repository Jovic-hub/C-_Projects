/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "Ticket.h"
#include "IOAble.h"
#include "Time.h"
namespace sdds {
    class Patient :public IOAble {
        char* m_name = nullptr;
        int OHIP = 0; 
        Ticket m_ticket = 0;
        bool m_fileIO = false;
    public:
        void setArrivalTime();
        Patient(const Patient&) = delete;
        Patient(int ticket = 0, bool flag = false);
        ~Patient();
        virtual char type()const = 0;
        bool fileIO()const;
        void fileIO(bool flag);
        bool operator==(const Patient& character)const;
        bool operator==(char character)const;
        operator Time()const;
        int number()const;
        std::ostream& csvWrite(std::ostream& ostr)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif 

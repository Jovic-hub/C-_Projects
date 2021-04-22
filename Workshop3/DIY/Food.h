/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_itemName[31];
        int m_time;
        int m_calories;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int time);
        void display()const;
        bool isValid()const;
        double calories()const;
    };
}

#endif 

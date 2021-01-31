/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"

    namespace sdds {
    struct Population {
        char* m_PostalCode;
        int m_population;
    };
    void sort();
    bool load(Population& st);
    bool load(const char* FILEname);
    void display();
    void display();
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_
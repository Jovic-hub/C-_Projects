
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

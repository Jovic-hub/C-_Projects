/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "cstring.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfPeople;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPeople - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].m_population > population[j + 1].m_population) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& st) {
        bool ok = false;
        char postal_code[128];
        if (read(postal_code) && read(st.m_population)) {
            int size = strlen(postal_code);
            st.m_PostalCode = new char[size + 1];
            strcpy(st.m_PostalCode, postal_code);
            ok = true;
        }
        return ok;
    }

    bool load(const char* FILEname) {
        bool ok = false;
        int i = 0;
        if (openFile(FILEname)) {
            noOfPeople = noOfRecords();
            population = new Population[noOfPeople];
            for (i = 0; i < noOfPeople; i++) {
                Population a;
                if (load(a)) {
                    population[i] = a;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                }
            }
            ok = true;
            closeFile();
        }
        else {
            cout << "Could not open data file: " << FILEname << endl;
        }
        return ok;
    }

    void display(const Population& st) {
        cout << "- " << st.m_PostalCode << ":  " << st.m_population;
    }
    
    void display() {
        int total_population = 0;
        sort();
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < noOfPeople; i++) {
            cout << i + 1;
            display(population[i]);
            cout << endl;
            total_population += population[i].m_population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total_population << endl;
    }
   
    void deallocateMemory() {

        for (int i = 0; i < noOfPeople; i++) {
            delete[] population;
            population = nullptr;
        }

    }

}
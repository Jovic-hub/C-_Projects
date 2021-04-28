
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#include "cstring.h"
#include "File.h" 
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   
   bool load(Employee& st) {

      bool ok = false;
      char name[128];
     

        if (read(st.m_empNo) && read(st.m_salary) && read(name)) {

            int size = strLen(name);
            st.m_name = new char[size + 1];
            strCpy(st.m_name, name);
            return true;
        }

      return ok;
   }     
   
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords();
         employees = new Employee[noOfEmployees];  
         for (i = 0; i < noOfEmployees; i++) {
             Employee a;
             if (load(a)) {
                 employees[i] = a;
             }
             else {
                 cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                 return false;
             }
         }
         return true;
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(const Employee& employee) { 
       cout << employees->m_empNo << employees->m_name << employees->m_salary << endl;
   }

   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", " << employees[i].m_salary << endl;
       }
   }

   void deallocateMemory() {
       delete[] employees->m_name;
       employees->m_name = nullptr;

       delete[] employees;
       employees = nullptr;
    }
}





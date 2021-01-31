/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP244 - NGG
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   
   bool read(char* name) {
       if (fscanf(fptr, "%[^\n]\n", name) != 1) {
            return false;
       }
       else {
           return true;
       }
   }
   bool read(int &emNo) {
       if (fscanf(fptr, "%d,", &emNo) != 1) {
           return false;
       }
       else {
           return true;
       }
   }
   bool read(double &ref) {
       if (fscanf(fptr, "%lf,", &ref) != 1) {
           return false;
       }
       else {
           return true;
       }
   }
}
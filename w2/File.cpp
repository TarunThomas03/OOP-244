/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 24-5-2023
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE* fptr;
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords()
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }

    // TODO: read functions go here
    // Reads the name of the employee 
    bool read(char* empName)
    {
        return fscanf(fptr, "%[^\n]\n", empName) == 1;
    }

    // Reads employee number 
    bool read(int& empNumber)
    {
        return fscanf(fptr, "%d,", &empNumber) == 1;
    }

    // Reads the employee salary 
    bool read(double& empSalary)
    {
        return fscanf(fptr, "%lf,", &empSalary) == 1;
    }
} // namespace sdds
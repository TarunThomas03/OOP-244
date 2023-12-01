/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 27-5-2023
*/

#pragma once
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
    struct PostalCode
    {
        char* code;
        int population;
    };

    // New Functions:
    void sort();
    bool load(const char filename[]);
    bool load(PostalCode& post);
    void display(const PostalCode& code);
    void display();
    void deallocateMemory();

} 
#endif // SDDS_POPULATION_H_

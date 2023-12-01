/*
Name: Tarun Thomas
Section : NCC
ID : 113605224
Date : 17 - 6 - 2023
*/

#pragma once
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds
{
    class Mark
    {
        int _mark;

    public:
        Mark();
        Mark(const int input);
        ~Mark() {};
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator+=(const int input);
        Mark& operator=(const int input);

    };
    int operator+=(int& _value, const Mark& _add);
}
#endif

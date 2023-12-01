/*
Name: Tarun Thomas
Section : NCC
ID : 113605224
Date : 17 - 6 - 2023
*/

#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {
    Mark::Mark()
    {
        _mark = 0;
    }

    Mark::Mark(const int input)
    {

        if (input >= 0 && input <= 100) {
            _mark = input;
        }
        else _mark = -1;
    }

    Mark::operator int() const
    {
        int result = 0;

        if (_mark >= 0 && _mark <= 100)
            result = _mark;

        return result;
    }

    Mark::operator double() const
    {
        double result = 0.0;

        if (_mark >= 50 && _mark < 60)        result = 1.0;
        else if (_mark >= 60 && _mark < 70)   result = 2.0;
        else if (_mark >= 70 && _mark < 80)   result = 3.0;
        else if (_mark >= 80 && _mark <= 100) result = 4.0;

        return result;
    }

    Mark::operator char() const
    {
        char result = 'X';

        if (_mark >= 0 && _mark < 50)         result = 'F';
        else if (_mark >= 50 && _mark < 60)   result = 'D';
        else if (_mark >= 60 && _mark < 70)   result = 'C';
        else if (_mark >= 70 && _mark < 80)   result = 'B';
        else if (_mark >= 80 && _mark <= 100) result = 'A';

        return result;
    }

    Mark& Mark::operator+=(const int input)
    {
        if (_mark >= 0 && _mark <= 100)
            _mark += input;

        return *this;
    }

    Mark& Mark::operator=(const int input)
    {
        _mark = input;

        return *this;
    }

    int operator+=(int& _value, const Mark& _add)
    {
        int temp = int(_add);

        if (temp >= 0 && temp <= 100)
            _value += temp;

        return _value;
    }

}
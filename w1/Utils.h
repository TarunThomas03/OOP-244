#pragma once
/*
 Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 16-5-2023
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

#endif //SDDS_UTILS_H

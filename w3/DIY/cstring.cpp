/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 3-6-2023
*/
#include "cstring.h"
namespace sdds {
    int strLen(const char* s)
    {
        int length = 0;

        while (s[length])
        {
            length++;
        }

        return length;
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;

        if (strLen(src) >= len)
        {
            while (i < len)
            {
                des[i] = src[i];
                i++;
            }
        }
        else
        {
            while (i < strLen(src))
            {
                des[i] = src[i];
                i++;
            }
        }
        des[i] = '\0';
    }
}
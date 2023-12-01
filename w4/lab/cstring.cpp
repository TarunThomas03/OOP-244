/*
Name       : Tarun Thomas
Student ID : 113605224
Section    : NCC
Date       : 8/6/2023
*/
#include "cstring.h"
namespace sdds {
    // strLen: Calculate the length of the C-String in characters
    int strLen(const char* s)
    {
        int length = 0;

        while (s[length]) {
            length++;
        }

        return length;
    }

    // strCpy: Cpies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        int i = 0;

        while (src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    // strCmp: Compares two C-strings
    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, result = 0;
        bool flag = false;

        while (!flag) {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
                result = s1[i] - s2[i];
                flag = true;
            }

            i++;
        }

        return result;
    }
}
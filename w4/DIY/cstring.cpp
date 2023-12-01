/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 10-6-2023
*/
#include "cstring.h"
namespace sdds {
 // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s)
  {
    int length = 0;

    while (s[length]) {
      length++;
    }

    return length;
  }

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    while (src[i]) {
      des[i] = src[i];
      i++;
    }

    des[i] = '\0';
  }
}
#pragma once
/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 12-7-2023
*/

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds
{
  int strLen(const char *s);
  void strCpy(char *des, const char *src);
  int strCmp(const char *s1, const char *s2);
}
#endif // !SDDS_CSTRING_H_
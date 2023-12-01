#pragma once
/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 5-7-2023
*/
#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds
{
   int strLen(const char* s);
   void strCpy(char* des, const char* src);
   void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_
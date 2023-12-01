/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 2-6-2023
*/
#include "cstring.h"
namespace sdds {
  
	int strLen(const char* s)
	{
		int i = 0; // inializing an integer to acess index 0 and correctly determine the lenght of the string


		while (s[i] != '\0') // As long as the string index does not equal null temrinator go to the next index within the character array, since strings are considered character arrays the next index means next index of the character array not the string array.
		{
			i++;
		}

		return i; // Return the lenght of the string 
	}

    // strnCpy: Copies the source character string into the destination by max lenght determined by len.
    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;

        if (strLen(src) >= len) {
            // Set the "while" loop to copy the 'src' as long as 'len'
            while (i < len) {
                des[i] = src[i];
                i++;
            }
        }
        else
        {
            // Set the "while" loop to copy the 'src' as long as the length of 'src'
            while (i < strLen(src)) {
                des[i] = src[i];
                i++;
            }
        }
        // Set the last index to be NULL value
        des[i] = '\0';
    }
}
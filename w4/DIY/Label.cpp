/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 10-6-2023
*/

#include <iostream>
#include "Label.h"
#include "cstring.h"

using namespace std;

namespace sdds {
    Label::Label()
    {
        strCpy(symbol, defaultSymbol);

        oneLineText = nullptr;
    }

    Label::Label(const char* frameArg)
    {        strCpy(symbol, frameArg);

        oneLineText = nullptr;
    }

    Label::Label(const char* frameArg, const char* content)
    {
        strCpy(symbol, frameArg);

        if (strLen(content) < 71) {
            oneLineText = new char[strLen(content) + 1];
            strCpy(oneLineText, content);
        }
    }

    Label::~Label()
    {
        if (oneLineText) {
            delete[] oneLineText;
            oneLineText = nullptr;
        }
    }

    void Label::readLabel()
    {
        char content[71];

        if (oneLineText != nullptr) {
            delete[] oneLineText;
            oneLineText = nullptr;
        }

        cout << "> ";
        cin.get(content, 71);

        cin.ignore(32767, '\n');

        oneLineText = new char[strLen(content) + 1];
        strCpy(oneLineText, content);
    }

    std::ostream& Label::printLabel() const
    {
        if (oneLineText != nullptr) {
            int middleSpace = strLen(oneLineText);

            cout << symbol[0];
            cout.fill(symbol[1]);
            cout.width(middleSpace + 3);
            cout << symbol[2] << endl;

            cout << symbol[7];
            cout.fill(' ');
            cout.width(middleSpace + 3);
            cout << symbol[3] << endl;

            cout << symbol[7];
            cout.width(middleSpace + 1);
            cout << oneLineText;
            cout << " " << symbol[3] << endl;

            cout << symbol[7];
            cout.fill(' ');
            cout.width(middleSpace + 3);
            cout << symbol[3] << endl;

            cout << symbol[6];
            cout.fill(symbol[5]);
            cout.width(middleSpace + 3);
            cout << symbol[4];
        }

        return cout;
    }
}
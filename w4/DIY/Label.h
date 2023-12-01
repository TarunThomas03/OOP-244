/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 10-6-2023
*/

#pragma once
#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

using namespace std;

namespace sdds {
    const char defaultSymbol[9] = "+-+|+-+|";

    class Label
    {
        char symbol[9];
        char* oneLineText;

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frmaeArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel() const;
    };
}
#endif // !SDDS_LABEL_H_

/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 10-6-2023
*/

#pragma once
#ifndef SDDS_LABELMARKER_H_
#define SDDS_LABELMARKER_H_

#include "Label.h"

using namespace std;

namespace sdds {
    class LabelMaker
    {
        Label* listOfLabels;
        int totalLabels;

    public:
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels();
    };
}
#endif // !SDDS_LABELMARKER_H_
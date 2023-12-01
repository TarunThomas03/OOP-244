/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 10-6-2023
*/

#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels > 0) {
            totalLabels = noOfLabels;

            listOfLabels = new Label[noOfLabels];
        }
        else {
            cout << "You can only input greater than zero" << endl;
            noOfLabels = 0;
        }
    }

    LabelMaker::~LabelMaker()
    {
        delete[] listOfLabels;
        listOfLabels = nullptr;
    }

    void LabelMaker::readLabels()
    {
        if (totalLabels > 0) {
            cout << "Enter " << totalLabels << " labels:" << endl;

            for (int i = 0; i < totalLabels; i++) {
                cout << "Enter label number " << i + 1 << endl;
                listOfLabels[i].readLabel();
            }
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < totalLabels; i++) {
            listOfLabels[i].printLabel();
            cout << endl;
        }
    }
}
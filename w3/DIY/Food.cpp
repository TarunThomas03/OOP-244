/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 3-6-2023
*/
#include <iostream>
#include "Food.h"
#include "cstring.h"
using namespace std;

namespace sdds {
    Food::Food()
    {
        m_foodName[0] = '\0';
        m_calNum = -1;
        m_timeOfConsum = 0;
    }

    Food::~Food() {}

    void Food::set(const char* name, int cal, int time)
    {
        if (name != nullptr && name[0] != '\0' && cal > -1 && cal <= 3000
            && time > 0 && time < 5) {
            strnCpy(m_foodName, name, 30);
            m_calNum = cal;
            m_timeOfConsum = time;
        }
    }

    bool Food::isValid() const
    {
        return m_foodName[0] != '\0';
    }

    int Food::calorie() const
    {
        return m_calNum;
    }

    void Food::display() const
    {
        if (isValid()) {
            display(m_foodName);

            cout << " | ";
            cout.width(4);
            cout << m_calNum;

            display(m_timeOfConsum);
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    void Food::display(const char* name) const
    {
        char pad = cout.fill('.');
        cout << "| ";
        cout.setf(ios::left);
        cout.width(30);
        cout << name;
        cout.fill(pad);
        cout.unsetf(ios::left);
    }

    void Food::display(int time) const
    {
        cout << " | ";
        cout.setf(ios::left);
        cout.width(11);

        switch (time) {
        case 1:
            cout << "Breakfast" << "|" << endl;;
            break;

        case 2:
            cout << "Lunch" << "|" << endl;;
            break;

        case 3:
            cout << "Dinner" << "|" << endl;;
            break;

        case 4:
            cout << "Snack" << "|" << endl;;
            break;
        }
        cout.unsetf(ios::left);
    }
}
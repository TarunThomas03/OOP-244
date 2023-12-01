/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 3-6-2023
*/
#include <iostream>
#include "CalorieList.h"

using namespace std;

namespace sdds {

    bool CalorieList::isValid() const
    {
        bool result = true;
        bool flag = true;

        for (int i = 0; i < m_noOfFood && flag; i++)
        {
            if (!m_food[i].isValid())
            {
                result = false;
                flag = false;
            }
        }

        return result;
    }

    int CalorieList::totalCal() const
    {
        int result = 0;

        for (int i = 0; i < m_noOfFood; i++) {
            // Adds all the calories of the food
            result += m_food[i].calorie();
        }

        return result;
    }

    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid()) {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::Footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;

        if (isValid()) {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << totalCal() << " |            |" << endl;
        }
        else {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }

        cout << "+----------------------------------------------------+" << endl;
    }


    CalorieList::CalorieList()
    {
        m_food = nullptr;
        m_noOfFood = 0;
        m_addedCount = 0;
    }

    CalorieList::~CalorieList()
    {
        if (m_food != nullptr) {
            delete[] m_food;
            m_food = nullptr;
        }
    };

    void CalorieList::init(int noOfList)
    {
        if (noOfList > 0) {
            m_noOfFood = noOfList;

            m_addedCount = 0;

            m_food = new Food[noOfList];
        }
    }

    bool CalorieList::add(const char* food_name, int calNum, int consumTime)
    {
        bool result = false;

        if (m_addedCount < m_noOfFood) {
            m_food[m_addedCount].set(food_name, calNum, consumTime);
            m_addedCount++;

            result = true;
        }

        return result;
    }

    void CalorieList::display() const
    {
        Title();

        for (int i = 0; i < m_noOfFood; i++) {
            m_food[i].display();
        }

        Footer();
    }

    void CalorieList::deallocate()
    {
        delete[] m_food;
        m_food = nullptr;
    }
}
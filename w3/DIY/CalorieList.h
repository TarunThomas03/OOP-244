/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 3-6-2023
*/
#include "Food.h"

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
namespace sdds {
    class CalorieList
    {
        int m_noOfFood;
        int m_addedCount;
        Food* m_food;

        bool isValid() const;
        int totalCal() const;
        void Title() const;
        void Footer() const;

    public:
        CalorieList(); 
        ~CalorieList();

        void init(int noOfList);
        bool add(const char* food_name, int calNum, int consumTime);
        void display() const;
        void deallocate();
    };
} // namespace sdds
#endif
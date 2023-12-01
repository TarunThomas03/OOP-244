/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 3-6-2023
*/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calNum;
        int m_timeOfConsum; 

    public:
        Food(); 
        ~Food();

        void set(const char* name, int cal, int time);
        bool isValid() const;
        int calorie() const;
        void display() const;
        void display(const char* name) const;
        void display(int time) const;

    };
}
#endif
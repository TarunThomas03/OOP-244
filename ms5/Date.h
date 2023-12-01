//***********************************************************************
// OOP244 MS5
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

using namespace std;

namespace sdds 
{
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = 
   {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;

   
   class Date
   {
   private:

      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;


      // returns number of days passed since the date 0001/1/1
      int daysSince0001_1_1()const;


      bool validate();             /* validates the date setting the error code and then returning the result 
                                    true, if valid, and false if invalid.*/

      // sets the error code
      void errCode(int);          

      // returns the current system year
      int systemYear()const;      

      // return true if
      bool bad()const;

      // returns the number of days in current month
      int mdays()const;

      // sets the date to the current date (system date)
      void setToToday();

   public:

      // creates a date with current date
      Date();                      

      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the 
                                         error code accordingly */


      // returns the error code or zero if date is valid
      int errCode()const;         

      // returns a string corresponding the current status of the date
      const char* dateStatus()const;  

      // returns the m_CUR_YEAR value;
      int currentYear()const;  

      //////////// Student's task ////////////

      // Get returns number of days from private function
      int getDay()const;


      // Return the result of the object is valid
      operator bool() const;

      // This function reads a date from the console in the following format YYYY/MM/DD 
      istream& read(istream& is);

      // Date object is in a “bad” state (it is invalid) print the “dateStatus()”
      ostream& write(ostream& os) const;

     
   };
   
   // Operator to take-away
   int operator-(const Date& dateA, const Date& dateB);


   // Comparison operator overload methods
   bool operator==(const Date& dateA, const Date& dateB);
   bool operator!=(const Date& dateA, const Date& dateB);
   bool operator>=(const Date& dateA, const Date& dateB);
   bool operator<=(const Date& dateA, const Date& dateB);
   bool operator<(const Date& dateA, const Date& dateB);
   bool operator>(const Date& dateA, const Date& dateB);
   

   // Helper function for std in/out
   ostream& operator<<(ostream& os, const Date& RO);
   istream& operator>>(istream& is, Date& RO);

   // This will make the global variables added to "Date.h"
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;

}
#endif
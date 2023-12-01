// Final Project Milestone 1
// Date Module
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
#include "Date.h"

namespace sdds 
{
    // Global var.
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

    // Validate date format
   bool Date::validate() 
   {
      errCode(NO_ERROR);       // m_ErrorCode = 0

      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) // if invalid
      {
         errCode(YEAR_ERROR); // m_ErrorCode = 2
      }
      else if (m_mon < 1 || m_mon > 12) 
      {
         errCode(MON_ERROR);  // m_ErrorCode = 3
      }
      else if (m_day < 1 || m_day > mdays()) 
      {
         errCode(DAY_ERROR);  // m_ErrorCode = 4
      }
      return !bad();          // if valid return true
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   // Update systemYear and setToToday
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }

   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   // 
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }

   // Constructor to recieve date format
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) 
   {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }

   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode; // m_ErrorCode=0
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const 
   {
      return m_ErrorCode != 0;
   }


   //////////// Student's task ////////////

   // Get returns number of days from private function
   int Date::getDay() const
   {
       return daysSince0001_1_1();
   }


   // return the result true of the object is valid
   Date::operator bool() const
   {
       return  !bad(); // if valid return true
   }


   // This function reads a date from the console in the following format YYYY/MM/DD 
   /// Get date function
   istream& Date::read(istream& is)
   {
       // clear error 
       errCode(NO_ERROR);

       // read year, month, data and ignore a single character "/" for month and year
       is >> m_year;
       is.ignore();
       is >> m_mon;
       is.ignore();
       is >> m_day;

       // validate date format
       if (!is)  
       {
           // No flushes keyboard when done reading process
           errCode(CIN_FAILED);
       }
       else
       {
           validate();
       }
    
      
       return is; 
   }

   // Date object is in a “bad” state (it is invalid) print the “dateStatus()”
   ostream& Date::write(ostream& os) const
   {

       // Validate object - return false if valid
       if (bad()) 
       {
           os<< dateStatus();
       }
       else
       {
           // Display dates
           os << m_year << "/" << setfill('0') << setw(2) << right << m_mon << "/";
           os << setfill('0') << setw(2) << right << m_day;

       }

       return os;
   }


   // Operator to take-away
   int operator-(const Date& dateA, const Date& dateB)
   {
       return  dateA.getDay() - dateB.getDay();
   }

   // Operator overload methods
   bool operator==(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() == dateB.getDay();
   }

   bool operator!=(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() != dateB.getDay();
   }

   bool operator>=(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() >= dateB.getDay();
   }

   bool operator<=(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() <= dateB.getDay();
   }

   bool operator<(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() < dateB.getDay();
   }

   bool operator>(const Date& dateA, const Date& dateB)
   {
       return dateA.getDay() > dateB.getDay();
   }

   // Helper function for std in/out
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

}

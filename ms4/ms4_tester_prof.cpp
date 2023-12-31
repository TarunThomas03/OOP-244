// Final Project Milestone 4
// Periodical Book 
// File	ms4_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Book.h"
#include "Utils.h"
#include "Date.h"


using namespace std;
using namespace sdds;
Book readBook(istream& istr) {
   Book P;
   istr >> P;
   return P;
}
Book getNextRec(ifstream& ifstr) {
   Book P;
   ifstr >> P;
   ifstr.ignore(1000, '\n');
   return P;
}

int main() {
   sdds::sdds_test = true;
   Book pd;
   cout << "An Invalid Book printout:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << "P1234" << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << "P123" << endl
      << "Seneca Handbook" << endl
      << "2021/13/17" << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << "P123" << endl
      << "The Story of My Experiments with Truth" << endl
      << "2021/11/17" << endl
      << "Mohandas Karamchand Gandhi" << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   cout << "You entered:" << endl;
   cout << pd << endl;
   cout << "And the title is agian: \"" << (const char*)pd << "\"" << endl;
   pd.set(12345);
   if (pd.onLoan()) {
      cout << "Now this publication is on loan to a member with the id: 12345" << endl;
//      pd.resetDate();
      cout << "The checkout date is: " << pd.checkoutDate() << endl;
      pd.setRef(9999);
      cout << "The library unique reference id is: " << pd.getRef() << endl;
      cout << pd << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
   cout << "Adding the Book to the end of the data file:" << endl;
   ofstream fileout("Books.txt", ios::app);
   if (pd) {
      cout << "appeneded to the file" << endl;
      fileout << pd << endl;
   }
   fileout.close();
   cout << endl << "Contents of the file:" << endl;
   ifstream filein("Books.txt");
   char pType{};
   for (int row = 1; filein; row++) {
      filein >> pType;
      if (pType != 'B') {
         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
         filein.setstate(ios::failbit);
      }
      filein.ignore();
      pd = getNextRec(filein);
      if (filein) {
         cout << (pd.onLoan() ? "|*" : "| ");
         cout.width(4);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row << (pd.onLoan()? "*": " ");
         cout.unsetf(ios::right);
         cout << pd << (pd == "Star" ? "<<<":"") << endl;
      }
   }
   return 0;
}
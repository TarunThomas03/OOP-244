/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 27-5-2023
*/

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
    int noOfPost;
    int noOfPopul;
    PostalCode* postcode;

    // Sorting
    void sort()
    {
        int i, j;
        PostalCode key;

        for (i = 1; i < noOfPost; i++) {
            key = postcode[i];

            for (j = i - 1; j >= 0 && postcode[j].population > key.population; j--) {
                postcode[j + 1] = postcode[j];
            }

            postcode[j + 1] = key;
        }
    }

    // Reads Postalcode
    bool load(PostalCode& post)
    {
        bool check = false;
        char code[7];

        if (read(code) && read(post.population)) {

            post.code = new char[strLen(code) + 1];
            strCpy(post.code, code);

            check = true;
        }

        return check;
    }

    bool load(const char filename[])
    {
        bool check = false;
        int i = 0;

        if (openFile(filename)) {
            noOfPost = noOfRecords();

            // Dynamic allocation of noOfPost to Postalcode
            postcode = new PostalCode[noOfPost];

            for (int j = 0; j < noOfPost; j++) {
                i += load(postcode[j]);
            }

            if (i != noOfPost)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else {
                check = true;
            }

            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }

        return check;
    }

    void display(const PostalCode& code)
    {
        cout << code.code << ":  " << code.population << endl;
    }

    void display()
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < noOfPost; i++) {
            cout << i + 1 << "- ";
            display(postcode[i]);
            noOfPopul += postcode[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << noOfPopul << endl;
    }

    void deallocateMemory()
    {
        // Deleting each struct with memory allocated
        for (int i = 0; i < noOfPost; i++) {
            delete[] postcode[i].code;
            postcode[i].code = nullptr;
        }

        // Deleting postcode alloacted memory
        delete[] postcode;
        postcode = nullptr;
    }
}
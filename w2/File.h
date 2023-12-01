
/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 24-5-2023
*/
#pragma once


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
	bool openFile(const char filename[]);
    void closeFile();
	int noOfRecords();
    // TODO: Declare read prototypes

	// Reads the name of the employee
	bool read(char* empName);

	// Reads employee number
	bool read(int& empNumber);

	// Reads the employee salary 
	bool read(double& empSalary);

} // namespace sdds
#endif // !SDDS_FILE_H_

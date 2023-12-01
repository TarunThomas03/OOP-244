/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 12-7-2023
*/

#pragma once
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
    class Truck : public MotorVehicle
    {
        double m_MaxCapacity{ 0.00 };
        double m_CurrCapacity{ 0.00 };

    public:
        Truck() {}
        Truck(const char* _license, int _year, double _capacity,
            const char* _address = nullptr);
        ~Truck() {}

        bool addCargo(const double cargo);
        bool unloadCargo();

        // Display the information of MotorVehicle
        std::ostream& write(std::ostream& os) const;

        // Receive new information from the user
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& ostr, const Truck& src);
    std::istream& operator>>(std::istream& istr, Truck& src);
}

#endif

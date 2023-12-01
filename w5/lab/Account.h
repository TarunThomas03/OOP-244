/*
Name: Tarun Thomas
Section : NCC
ID : 113605224
Date : 16 - 6 - 2023
*/

#pragma once
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;

        void setEmpty();

    public:
        Account();
        Account(const int number, const double balance);
        ~Account() {};
        std::ostream& display() const;

        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;
        Account& operator+=(const double _into);
        Account& operator-=(const double _draw);
        Account& operator>>(Account& _move);
        Account& operator<<(Account& _move);
        Account& operator=(const int _acc);
        Account& operator=(Account& _move);
        friend double operator+(const Account& _left, const Account& _right);
        friend double operator+=(double& _value, const Account& _add);
    };
} // namespace sdds
#endif // SDDS_ACCOUNT_H_


/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 2-6-2023
*/
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
    }

    void Item::setEmpty()
    {
        *m_itemName = '\0';
        m_price = 0.0;
    }

    void Item::set(const char* name, double price, bool taxed)
    {
        if (name != nullptr && price > 0)
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const
    {
        if (isValid()) {
            display(m_itemName);
            display(m_price);
            display(m_taxed);
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    void Item::display(const char* name) const
    {
        char pad = cout.fill('.');
        cout << "| ";
        cout.setf(ios::left);
        cout.width(20);
        cout << m_itemName;
        cout.fill(pad);
        cout.unsetf(ios::left);
    }

    void Item::display(double price) const
    {
        cout << " | ";
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << m_price;
        cout.unsetf(ios::fixed);
    }

    void Item::display(bool tax) const
    {

        if (tax == 1)
            cout << " | Yes |" << endl;
        else if (tax == 0)
            cout << " | No  |" << endl;
    }

    bool Item::isValid() const
    {
        bool result = false;
        if (*m_itemName != '\0' && m_price > 0)
            result = true;

        return result;
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        double result = 0.0;

        if (m_taxed) {
            result = (m_price * 0.13);
        }

        return result;
    }

}
/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 2-6-2023
*/
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax() const
    {
        double result = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            result += m_items[i].tax();
        }

        return result;
    }

    double Bill::totalPrice() const
    {
        double result = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            result += m_items[i].price();
        }

        return result;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title << " |" << endl;
            cout.unsetf(ios::left);
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {
            cout << "|                Total Tax: ";
            display(totalTax());
            cout << "|              Total Price: ";
            display(totalPrice());
            cout << "|          Total After Tax: ";
            display(totalTax() + totalPrice());
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty()
    {
        *m_title = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const
    {
        bool result = true;
        bool flag = true;

        for (int i = 0; i < m_noOfItems && flag; i++) {
            if (!m_items[i].isValid()) {
                result = false;
                flag = false;
            }
        }

        return result;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;

            m_itemsAdded = 0;

            strnCpy(m_title, title, 36);
            m_items = new Item[noOfItems];

            for (int i = 0; i < noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool result = false;

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);

            m_itemsAdded++;

            result = true;
        }

        return result;
    }

    void Bill::display() const
    {
        Title();

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    void Bill::display(double price) const
    {
        cout.width(10);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << price << " |" << endl;
        cout.unsetf(ios::fixed);
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}
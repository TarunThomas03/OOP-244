/*
Name       : Tarun Thomas
Student ID : 113605224
Section    : NCC
Date       : 8/6/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp
#include "Canister.h"

using namespace std;
namespace sdds {
    const double PI = 3.14159265;

    void Canister::setToDefault()
    {
        // Setting to their default values
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr)
    {
        // Checks that Cstr is not null and usable
        if (Cstr != nullptr && Cstr[0] != '\0' && m_usable) {
            deallocate();

            // Copies Cstr to newly allocated memory of m_contentName
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty() const
    {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C) const
    {
        bool result = false;

        if (this->m_contentName != nullptr && C.m_contentName != nullptr) {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)
                result = true;
        }

        return result;
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char* Cstr)
    {
        setToDefault();

        setName(Cstr);
    }

    Canister::Canister(double hieght, double diameter, const char* contentName)
    {
        setToDefault();

        // The smallest H & D: 10.0 by 10.0 and the largest one can be 40 by 30
        if (hieght >= 10.0 && diameter >= 10 && hieght <= 40 && diameter <= 30) {
            m_height = hieght;
            m_diameter = diameter;
            m_usable = true;
            setName(contentName);
        }
        else
            m_usable = false;
    }

    Canister::~Canister()
    {
        if (m_contentName) {
            delete[] m_contentName;
            m_contentName = nullptr;
        }
    }

    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == nullptr || contentName[0] == '\0')
            m_usable = false;

        else if (isEmpty())
            setName(contentName);

        else if (!hasSameContent(contentName))
            m_usable = false;

        return *this;
    }

    Canister& Canister::pour(double quantity)
    {
        // Adds the quantity argument to the content volume of the "this" Canister
        if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity())
            m_contentVolume += quantity;
        else
            m_usable = false;

        return *this;
    }

    Canister& Canister::pour(Canister& give)
    {
        setContent(give.m_contentName);

        if (give.volume() > (this->capacity() - this->volume())) {
            give.m_contentVolume -= (this->capacity() - this->volume());

            this->m_contentVolume = capacity();
        }
        else {
            pour(give.m_contentVolume);

            give.m_contentVolume = 0.0;
        }

        return *this;
    }

    double Canister::volume() const
    {
        return m_contentVolume;
    }

    std::ostream& Canister::display() const
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity();
        cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

        if (!m_usable)
            cout << " of Unusable content, discard!";
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << m_contentName;
        }

        cout.unsetf(ios::fixed);
        return cout;
    }

    double Canister::capacity() const
    {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear()
    {
        if (!m_usable) {
            deallocate();

            m_contentVolume = 0.0;
            m_usable = true;
        }
    }

    void Canister::deallocate()
    {
        if (m_contentName) {
            delete[] m_contentName;
            m_contentName = nullptr;
        }
    }
}
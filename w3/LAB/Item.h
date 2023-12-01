
/*
Name      : Tarun Thomas
 Email     : tthomas60@myseneca.ca
 Student ID: 113605224
 Date      : 2-6-2023
*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display() const;
        void display(const char* name) const;
        void display(double price) const;
        void display(bool tax) const;
        bool isValid() const;
        double price() const;
        double tax() const;
    };
}

#endif // !SDDS_SUBJECT_H

/*
Name       : Tarun Thomas
Student ID : 113605224
Section    : NCC
Date       : 8/6/2023
*/
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds
{
  class Canister
  {
    char *m_contentName;    
    double m_diameter;      
    double m_height;        
    double m_contentVolume; 
    bool m_usable;          

    void setToDefault();
    void setName(const char *Cstr);
    bool isEmpty() const;
    bool hasSameContent(const Canister &C) const;

  public:
    Canister();
    Canister(const char *contentName);
    Canister(double hieght, double diameter, const char *contentName = nullptr);
    ~Canister();
    Canister &setContent(const char *contentName);
    Canister &pour(double quantity);
    Canister &pour(Canister &);
    double volume() const;
    std::ostream &display() const;
    double capacity() const;
    void clear();
    void deallocate();
  };
} // namespace sdds
#endif // !SDDS_BOX_H
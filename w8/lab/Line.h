

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
  class Line : public LblShape
  {
    unsigned int m_length {0};

  public:
    Line() {}
    Line(const char *_label, int _length);
    virtual ~Line() {}

    void getSpecs(std::istream &istr);
    void draw(std::ostream &ostr) const;
  };
}
#endif
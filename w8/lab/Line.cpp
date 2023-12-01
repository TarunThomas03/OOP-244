

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
  Line::Line(const char *_label, int _length) : LblShape(_label)
  {
    if (_length > 0)
      m_length = _length;
  }

  void Line::getSpecs(std::istream &istr)
  {
    int _length;
    bool _escape = false;

    do {
      LblShape::getSpecs(istr);

      istr >> _length;

      if (!istr) {
        istr.clear();
        istr.ignore(32767, '\n');
      }
      else {
        istr.ignore();
        m_length = _length;
        _escape = true;
      }
    } while (!_escape);
  }

  void Line::draw(std::ostream &ostr) const
  {
    if (m_length > 0 && LblShape::label()) {
      ostr << LblShape::label() << endl;
      ostr.width(m_length);
      ostr.fill('=');
      ostr << '=';
    }
  }
}

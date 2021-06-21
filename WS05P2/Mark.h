#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        bool m_valid;
        void setEmpty();
    public:
        Mark();
        Mark(int mark);
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator+=(int addMark);
        Mark& operator=(int mark);
        bool isValid(int mark) const;
        double getGPA(int mark) const;
        char getGrade(int mark) const;
    };
    int operator+=(int&, const Mark&);
}
#endif // SDDS_MARK_H_
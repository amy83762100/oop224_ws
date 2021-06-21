#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    void Mark::setEmpty() {
        m_mark = -1; // invalid empty state
        m_valid = false;
    }
    Mark::Mark() {
        m_mark = 0;
        m_valid = true;
    }
    Mark::Mark(int mark) {
        setEmpty();
        if (isValid(mark)) {
            m_mark = mark;
            m_valid = true;
        }
    }
    Mark::operator int() const {
        return m_mark != -1 ? m_mark : 0;
    }
    Mark::operator double() const {
        return getGPA(m_mark);
    }
    Mark::operator char() const {
        return getGrade(m_mark);
    }
    Mark& Mark::operator+=(int addMark) {
        if (m_mark != -1) {
            m_mark += addMark;
            m_valid = isValid(m_mark);
            if (!m_valid)m_mark = 0;
        }
        return *this;
    }
    Mark& Mark::operator=(int mark) {
        m_valid = isValid(mark);
        m_mark = m_valid ? mark : 0;
        return *this;
    }
    bool Mark::isValid(int mark) const {
        return  (mark >= 0 && mark <= 100) ? true : false;
    }
    double Mark::getGPA(int mark) const{
        double gpa=0;
        if ((0 <= mark && mark < 50)||!m_valid) gpa = 0.0;
        else if (50 <= mark && mark < 60) gpa = 1.0;
        else if (60 <= mark && mark < 70) gpa = 2.0;
        else if (70 <= mark && mark < 80) gpa = 3.0;
        else if (80 <= mark && mark <= 100) gpa = 4.0;
        return gpa;
    }
    char Mark::getGrade(int mark) const {
        char grade = 'X';
        if (!m_valid) grade = 'X';
        else if (0 <= mark && mark < 50) grade = 'F';
        else if (50 <= mark && mark < 60) grade = 'D';
        else if (60 <= mark && mark < 70) grade = 'C';
        else if (70 <= mark && mark < 80) grade = 'B';
        else if (80 <= mark && mark <= 100) grade = 'A';
        return grade;
    }
    int operator+=(int& val, const Mark& mark) {
        return val += int(mark);
    }
}
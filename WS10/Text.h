// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// 
// Workshop 10:
// Version: 1.0
// Date: 2021/08/07
// Name: Pei-Yi Lin
// Email: plin24@myseneca.ca
// Student ID: 123423204
//
///////////////////////////////////////////////////
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength()const; // Code provided in Text.cpp
    protected:
        const char& operator[](int index)const;
    public:
        // Constructor
        Text(const char* filename = nullptr);
        // Copy Constructor
        Text(const Text& source);
        // Overloaded Assignmnet
        Text& operator=(const Text& source);
        // Destructor
        ~Text();
        void init(const Text& source);


        void read();
        virtual void write(std::ostream& os)const;
    };
    // prototype of insertion overload into ostream goes here
    std::ostream& operator<<(std::ostream& os, const Text& T);
}
#endif // !SDDS_PERSON_H__


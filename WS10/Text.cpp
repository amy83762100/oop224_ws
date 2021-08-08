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
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
    Text::Text(const char* filename) {
        m_content = nullptr;
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
        else m_filename = nullptr;
    }
    void Text::init(const Text& source) {
        if (source.m_filename) {
            m_filename = new char[strlen(source.m_filename) + 1];
            strcpy(m_filename, source.m_filename);
        }
        if (source.m_content) {
            m_content = new char[strlen(source.m_content) + 1];
            strcpy(m_content, source.m_content);
        }
    }
    Text::Text(const Text& source) {
        init(source);
    }
    Text& Text::operator=(const Text& source) {
        // Check for self assignment
        if (this != &source) {
            delete[] m_filename;
            delete[] m_content;
            init(source);
        }
        return *this;
    }
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }
    ostream& operator<<(ostream& os, const Text& T) {
        T.write(os);
        return os;
    }
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
   const char& Text::operator[](int index)const {
       return m_content[index];
   }
   void Text::read() {
       ifstream fin(m_filename);
       if (fin.is_open())
       {
           int len = getFileLength();
           m_content = new char[len+1];
           for (int i = 0; fin || i == len; i++) {
               fin.get(m_content[i]);
           }
           m_content[len] = '\0';
       }
   }
   void Text::write(std::ostream& os)const {
       if (m_content) os << m_content;
   }
}
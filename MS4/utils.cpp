/* Citation and Sources...
Final Project Milestone 4
Module: Time
Filename: Time.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/23  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   int getInt(const char* prompt) {
       int value;
       bool valid = false;
       bool isDigit;
       char* s;
       string str;
       if (prompt != nullptr) cout << prompt;
       while (!valid) {
           isDigit = true;
           getline(cin, str, '\n');
           s = new char[str.length() + 1];
           strcpy(s, str.c_str());
           if (!isdigit(s[0])&&s[0]!='-') cout << "Bad integer value, try again: ";
           else {
               for (int i = 1; (unsigned) i < str.length(); i++) {
                   if (!isdigit(s[i])) isDigit = false;
               }
               if (!isDigit) cout << "Enter only an integer, try again: ";
               else {
                   value = stoi(s); valid = true;
               }
           }
           delete[] s;
       }
       return value;
   }
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       int value;
       bool valid = false;
       value = getInt(prompt);
       while (!valid) {
           if (value < min || value > max) {
               cout << errorMessage;
               if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
               value = getInt();
           }
           else valid = true;
       }
       return value;
   }
   char* getcstr(const char* prompt, std::istream& istr, char delimiter){
       char* s;
       string str;
       if (prompt != nullptr) cout << prompt;
       getline(istr, str, delimiter);
       int len = str.length();
       s = new char[len + 1];
       strcpy(s, str.c_str());
       str[len] = '\0';
       return s;
   }
}
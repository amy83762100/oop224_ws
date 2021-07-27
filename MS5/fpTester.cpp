/* Citation and Sources...
Final Project Milestone 5
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PreTriage.h"
#include "utils.h"
using namespace std;
using namespace sdds;
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void copyFile(const char* des, const char* src) {
   ifstream s(src);
   ofstream d(des);
   char ch = 0;
   while (s.get(ch) && d << ch);
}
void fp1tester() {
   ofstream("data.csv").close();
   sdds::debug = true;
   PreTriage P("data.csv");
   P.run();
}
void fp2tester() {
   copyFile("smalldata.csv", "smalldata.csv.bak");
   sdds::debug = true;
   PreTriage P("smalldata.csv");
   P.run();
}
void fp3tester() {
   copyFile("bigdata.csv", "bigdata.csv.bak");
   sdds::debug = true;
   PreTriage P("bigdata.csv");
   P.run();
}
int main() {
   fp1tester();
   displayFile("data.csv");
   fp3tester();
   displayFile("bigdata.csv");
   fp2tester();
   displayFile("smalldata.csv");
   return 0;
}



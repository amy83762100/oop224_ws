///* Citation and Sources...
//Final Project Milestone 5
//Version 1.0
//Author Pei-Yi Lin
//Revision History
//-----------------------------------------------------------
//Date      Reason
//2021/7/27  Preliminary release
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------
//-----------------------------------------------------------*/
//#include <iostream>
//#include <fstream>
//#include "PreTriage.h"
//#include "utils.h"
//
//using namespace sdds;
//using namespace std;
//
//void displayFile(const char* fname) {
//   ifstream fin(fname);
//   char ch;
//   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
//   while (fin.get(ch)) cout << ch;
//   cout << "***************************************************" << endl << endl;
//}
//void copyFile(const char* des, const char* src) {
//   ifstream s(src);
//   ofstream d(des);
//   char ch = 0;
//   while (s.get(ch) && d << ch);
//}
//
//int main() {
//   sdds::debug = true;
//   copyFile("bigdata.csv", "bigdata.csv.bak");
//   PreTriage P("bigdata.csv");
//   P.run();
//   return 0;
//}
//

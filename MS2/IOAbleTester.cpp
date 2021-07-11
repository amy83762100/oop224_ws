// ioable tester:
// version: 1.0
// date: 2021-06-23
// author: fardad soleimanloo
// description:
// this file tests the ioable module of your project
/////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "ioable.h"
using namespace std;
using namespace sdds;
void displayfile(const char* filename) {
   ifstream file(filename);
   cout << filename << "---------------------" << endl;
   char ch;
   while (file.get(ch) && cout << ch);
   cout << "---------------------------------" << endl;
}
class box :public ioable {
   int m_hieght, m_width;
public:
   bool csv;
   box() :m_hieght(0), m_width(0), csv(false) {
      cout << "defaulting box" << endl;
   };
   ostream& csvwrite(std::ostream& ostr)const {
      return ostr << m_hieght << "," << m_width;
   }
   istream& csvread(std::istream& istr) {
      istr >> m_hieght;
      istr.ignore();
      istr >> m_width;
      istr.ignore();
      return istr;
   }
   ostream& write(ostream& ostr)const {
      if (csv) {
         csvwrite(ostr);
      }
      else {
         int i;
         for (int j = 0; j < m_hieght; j++) {
            for (i = 0; i < m_width * 2; i++, ostr << "*");
            ostr << endl;
         }
      }
      return ostr;
   }
   istream& read(istream& istr) {
      if (csv) {
         csvread(istr);
      }
      else {
         cout << "height: ";
         istr >> m_hieght;
         cout << "width: ";
         istr >> m_width;
      }
      return istr;
   }
   ~box() {
      cout << "box(" << m_hieght << "," << m_width  << ") is gone!" << endl;
   }
};
int main() {
   box b;
   cout << "getting information of an ioable box from console: " << endl;
   cin >> b;
   cout << "display the ioable box on console: " << endl;
   cout << b << endl;
   b.csv = false;
   ifstream fboxes("boxes.txt");
   if (fboxes) {
      box* bp;
      ofstream bout("boxesout.txt");
      b.csv = true;
      cout << "saving " << b << " in the output file." << endl;
      bout << b << endl;
      cout << "dynamically allocating a box and holding it in an ioable pointer..." << endl;
      ioable* iop = bp = new box();
      cout << "reading dimenstions from file using the ioalbe pointer" << endl;;
      bp->csv = true;
      fboxes >> *iop;
      cout << "dimentions: " << endl;
      cout << *iop << endl;
      bp->csv = false;
      cout << "what it looks like on screen:" << endl << *iop << endl;
      bp->csv = true;
      cout << "now save it in the file..." << endl;
      bout << *iop << endl;
      cout << "reading the next dimenstions from file using the ioable pointer" << endl;;
      fboxes >> *iop;
      cout << "dimentions: " << endl;
      cout << *iop << endl;
      bp->csv = false;
      cout << "what it looks like on screen:" << endl << *iop << endl;
      bp->csv = true;
      cout << "save this one in the output file too..." << endl;
      bout << *iop << endl;
      cout << "close the file and display it..." << endl;
      bout.close();
      displayfile("boxesout.txt");
      cout << "removing the box from memory using the ioable pointer..." << endl;
      delete bp;
      bout.close();
   }
   else {
      cout << "could not find the file \"boxes.txt\"." << endl;
   }
   cout << "content of \"boxesout.txt\" file" << endl;
   displayfile("boxesout.txt");
   return 0;
}

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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& source);
      HtmlText& operator=(const HtmlText& source);
      ~HtmlText();
      void init(const HtmlText& source);
      void write(std::ostream& os)const;
   };
}
#endif // !SDDS_HTMLTEXT_H__

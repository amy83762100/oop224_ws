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
#include "HtmlText.h"
using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename) {
		m_title = nullptr;
		if (title) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& source){
		init(source);
	}
	HtmlText& HtmlText::operator=(const HtmlText& source) {
		if (this != &source) {
			delete[] m_title;
			init(source);
		}
		return *this;
	}
	void HtmlText::init(const HtmlText& source) {
		if (source.m_title) {
			m_title = new char[strlen(source.m_title) + 1];
			strcpy(m_title, source.m_title);
			Text::operator=(source);
		}
	}
	void HtmlText::write(ostream& os)const {
		bool MS = false;
		os << "<html><head><title>";
		os << (m_title ? m_title : "No Title");
		os << "</title></head>\n<body>\n";
		if (m_title) os << "<h1>" << m_title << "</h1>\n";
		for (int i = 0; (*this)[i]!='\0'; i++) {
			char value = (*this)[i];
			switch (value)
			{
			case ' ': {
				if (MS) os << "&nbsp;";
				else { MS = true; os << ' ';}
				break;
			}
			case '<': {
				os << "&lt;";
				MS = false;
				break;
			}
			case '>': {
				os << "&gt;";
				MS = false;
				break;
			}
			case '\n': {
				os << "<br />\n";
				MS = false;
				break;
			}
			default:
				MS = false;
				os << value;
				break;
			}
		}
		os << "</body>\n</html>";
	}
}
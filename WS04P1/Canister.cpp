 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
	const double PI = 3.14159265;
	void Canister::setToDefault(){
		m_contentName = nullptr;
		m_diameter = 10;
		m_height = 13;
		m_contentVolume = 0;
		m_usable = true;
	}
	bool Canister::isEmpty()const {
		return  m_contentVolume < 0.00001 ? true : false;
	}
	bool Canister::hasSameContent(const Canister& C)const {
		return m_contentName!=nullptr&&strCmp(m_contentName, C.m_contentName) ? true : false;
	}
	void Canister::setName(const char* Cstr){
		if (Cstr != nullptr && m_usable == true) {
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentName = new char[strLen(Cstr)+1];
			strCpy(m_contentName, Cstr);
		}	
	}
	Canister::Canister() {
		setToDefault();
	}
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}
	Canister::Canister(double hieght, double diameter, const char* contentName){
		setToDefault();
		if (hieght >= 10 && hieght <= 40 && diameter >= 10 && diameter <= 30) {
			m_height = hieght;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
		else m_usable = false;
	}
	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}
	void  Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0;
		m_usable = true;
	}
	double Canister::capacity()const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}
	double Canister::volume()const {
		return m_contentVolume;
	}
	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) m_usable = false;
		else if (isEmpty()) setName(contentName);
		else if (hasSameContent(contentName)) m_usable = false;
		return *this;
	}
	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0 && (quantity + volume()) <= capacity()) m_contentVolume += quantity;
		else m_usable = false;
		return *this;
	}
	Canister& Canister::pour(Canister& C){
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume())) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0;
		}
		return *this;
	}
	std::ostream& Canister::display()const {
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<< capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable)  cout << " of Unusable content, discard!";
		else if (m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout.setf(ios::right);
			cout << volume();
			cout << "cc   ";
			cout.unsetf(ios::right);
			cout<< m_contentName;
		}
		return cout;
	}
}
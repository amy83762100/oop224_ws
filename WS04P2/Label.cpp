#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"
#include "label.h"
using namespace std;
namespace sdds {
    void Label::setToDefault() {
        l_content = nullptr;
    }
    void Label::setContent(const char* Cstr) {
        if (Cstr != nullptr) {
            delete[] l_content;
            l_content = nullptr;
            l_content = new char[strLen(Cstr) + 1];
            strCpy(l_content, Cstr);
        }
    }
    Label::Label(){
        setToDefault();
        strnCpy(l_frame, "+-+|+-+|",8);
    }
    Label::Label(const char* frameArg) {
        setToDefault();
        strnCpy(l_frame, frameArg,8);
    }
    Label::Label(const char* frameArg, const char* content){
        setToDefault();
        strnCpy(l_frame, frameArg, 8);
        setContent(content);
    }
    Label::~Label(){
        delete[] l_content;
        l_content = nullptr;
    }
    void Label::readLabel(){
        char content[70];
        cin.getline(content, 70);
        setContent(content);
    }
    std::ostream& Label::printLabel()const{
        if (l_content != nullptr) {
            int len = (strLen(l_content) + 3);
            cout << l_frame[0] << setfill(l_frame[1]) << setw(len) << l_frame[2] << endl;
            cout << l_frame[7] << setfill(' ') << setw(len) << l_frame[3] << endl;
            cout << l_frame[7] << ' ' << l_content << ' ' << l_frame[3] << endl;
            cout << l_frame[7] << setfill(' ') << setw(len) << l_frame[3] << endl;
            cout << l_frame[6] << setfill(l_frame[5]) << setw(len) << l_frame[4] << endl;
        }
        return cout;
    }
}
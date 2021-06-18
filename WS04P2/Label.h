#ifndef LABEL_H
#define LABEL_H
#include <iostream>
namespace sdds {
    class Label {
        char l_frame[9];
        char* l_content;
    public:
        void setToDefault();
        void setContent(const char* Cstr);
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
    };
}

#endif // !LABEL_H
#ifndef LABELMAKER_H
#define LABELMAKER_H
#include "Label.h"
namespace sdds {
    class LabelMaker {
        int l_noOfLabels;
        Label* l_labels;
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif // !LABELMAKER_H
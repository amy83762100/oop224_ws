#define _CRT_SECURE_NO_WARNINGS
#include <ostream>
#include "LabelMaker.h"
using namespace std;
namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels){
        l_noOfLabels = noOfLabels;
        delete[] l_labels;
        l_labels = nullptr;
        l_labels = new Label[noOfLabels];
    }
    void LabelMaker::readLabels(){
        cout << "Enter " << l_noOfLabels << " labels:" << endl;
        for (int i = 0; i < l_noOfLabels; i++) {
            cout << "Enter label number " << i+1 << endl;
            l_labels[i].readLabel();
        }
    }
    void LabelMaker::printLabels(){
        for (int i = 0; i < l_noOfLabels; i++) l_labels[i].printLabel();
    }
    LabelMaker::~LabelMaker(){
        delete[] l_labels;
        l_labels = nullptr;
    }
}
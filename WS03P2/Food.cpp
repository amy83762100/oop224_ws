#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    void Food::setName(const char* name) {
        strnCpy(c_foodName, name, 30);
    }
    void Food::setEmpty() {
        c_foodName[0] = '\0';
        c_calorie = 0;
        c_timeOfconsumption = 0;
    }
    void Food::set(const char* name, int calorie, int timeOfconsumption) {
        bool valid = calorie > 0 && c_calorie<=3000 && name != nullptr && timeOfconsumption>=1 && timeOfconsumption<=4;
        if (valid) {
            setName(name);
            c_calorie = calorie;
            c_timeOfconsumption = timeOfconsumption;
        }
        else
            setEmpty();
    }
    int Food::calorie()const {
        return c_calorie;
    }
    int Food::timeOfconsumption()const {
        return c_timeOfconsumption;
    }
    bool Food::isValid()const {
        return  c_foodName != nullptr && c_calorie > 0 && c_calorie <=3000 && c_timeOfconsumption >= 1 && c_timeOfconsumption <= 4;
    }
    void Food::display()const {

        if (isValid()) {
            cout << "| ";
            cout.width(30);
            cout.setf(ios::left);
            cout.fill('.');
            cout << c_foodName;
            cout << " | ";
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << c_calorie;
            cout << " | ";
            cout.width(10);
            cout.unsetf(ios::right);
            switch (c_timeOfconsumption) {
            case 1:
                cout << "Breakfast";
                break;
            case 2:
                cout << "Lunch";
                break;
            case 3:
                cout << "Dinner";
                break;
            case 4:
                cout << "Snack";
                break;
            }
            cout << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

}
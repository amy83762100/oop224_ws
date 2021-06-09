#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char c_foodName[31];
        int c_calorie;
        int c_timeOfconsumption;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie,int timeOfconsumption);
        void display()const;
        bool isValid()const;
        int calorie()const;
        int timeOfconsumption()const;
    };
}
#endif // !SDDS_FOOD_H_

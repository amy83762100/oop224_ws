#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct PopReport{
        char* postalCode;
        int population;
    };
    void sort();
    bool load(PopReport& report);
    bool load(const char* filename);
    void display(const PopReport& report);
    void display();
    void deallocateMemory();
}
#endif // SDDS_POPULATION_H_
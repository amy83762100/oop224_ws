#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
    int noOfPopRecords;
    PopReport* records;

    void sort() {
        int i, j;
        PopReport temp;
        for (i = noOfPopRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (records[j].population > records[j + 1].population) {
                    temp = records[j];
                    records[j] = records[j + 1];
                    records[j + 1] = temp;
                }
            }
        }
    }
    bool load(PopReport& record) {
        bool ok = false;
        char postalCode[128];
        int population;

        if (read(postalCode) && read(population)) {
            record.postalCode = new char[strLen(postalCode) + 1];
            strCpy(record.postalCode, postalCode);
            record.population = population;
            ok = true;
        }
        return ok;
    }
    bool load(const char* filename) {
        bool ok = false;
        int i = 0;
        if (openFile(filename)) {
            noOfPopRecords = noOfRecords();
            records = new PopReport[noOfPopRecords];
            while (i < noOfPopRecords)
            {
                load(records[i]);
                i++;
            }
            if (noOfPopRecords != i) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }
    void display(const PopReport& record) {
        cout << record.postalCode << ": " << record.population << endl;
    }
    void display() {
        int sum = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfPopRecords; i++) {
            cout << (i + 1) << "- ";
            display(records[i]);
            sum += records[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: "<< sum << endl;
    }
    void deallocateMemory() {
        for (int i = 0; i < noOfPopRecords; i++) {
            delete[] records[i].postalCode;
            records[i].postalCode = nullptr;
        }
        delete[] records;
        records = nullptr;
    }
}
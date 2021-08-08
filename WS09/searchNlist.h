#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds{
	template <typename T1, typename T2>
	bool search(Collection<T1>& c, T1 arr[], int numOfEl, T2 key) {
		bool found = false;
		for (int i = 0; i < numOfEl; i++) {
			if (arr[i] == key)
			{
				found = true;
				c.add(arr[i]);
			}
		}
		return found;
	}
	template <typename T>
	void listArrayElements(const char* title, T arr[], int numOfEl) {
		cout << title << endl;
		for (int i = 0; i < numOfEl; i++) {
			cout << i + 1 << ": " << arr[i];
			cout << endl;
		}
	}
}
#endif // !SDDS_SEARCHNLIST_H_

#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
			if ((i+1)==len||src[i + 1] == '\0') des[i + 1] = '\0';
		}
	}
}
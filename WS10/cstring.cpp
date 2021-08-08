#include "cstring.h"

namespace sdds {

	void strCpy(char* des, const char* src) {
		for (int i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
			if (src[i + 1] == '\0') des[i + 1] = '\0';
		}
	}

	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
			if ((i + 1) == len || src[i + 1] == '\0') des[i + 1] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0') {
			i++;
		}
		return s1[i] - s2[i];
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		while (i < len - 1 && s1[i] == s2[i] && s1[i] != '\0') {
			i++;
		}
		return s1[i] - s2[i];
	}

	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
	}

	const char* strStr(const char* str1, const char* str2) {
		bool found = false;
		static char str[80];
		int x = 0;
		for (int i = 0; str1[i] != '\0'; i++) {

			for (int j = 0; str2[j] != '\0' && str2[j] == str1[i + j] && found == false; j++) {
				if (str2[j + 1] == '\0') found = true;
			}
			if (found) {
				str[x] = str1[i];
				x++;
				if (str1[i + 1] == '\0') str[x] = '\0';
			}
		}
		if (!found) {
			return nullptr;
		};
		return str;
	}

	void strCat(char* des, const char* src) {
		int i = 0;
		while (des[i] != '\0') {
			i++;
		}
		for (int j = 0; src[j] != '\0'; j++) {
			des[i + j] = src[j];
			if (src[j + 1] == '\0') des[i + j + 1] = '\0';
		}

	}
}
#include <iostream>
#include <cstring>
using namespace std;
#include "Utils.h"
namespace sdds {
	long long int read2(int min,long long int max, const char* ErrorMess) {
		long long int val;
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
		return val;
	}

	/*void read(int& val, int min, int max, const char* ErrorMess) {
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}*/

	void read1(char* str, int len, const char* errorMessage) {
		bool ok;
		do {
			ok = true;
			cin.getline(str, len + 1, '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				ok = false;
			}
			else if (strlen(str) == 0)
				ok = false;
		} while (!ok && cout << errorMessage);
	}


}
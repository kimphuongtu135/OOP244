/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is implementation file of Tools, it contains helper functions. 
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX_REC_NO 100

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"
using namespace std;

namespace sdds
{

	void toLowerCase(char* lowerCase, const char* str) { 
		int i;
		for (i = 0; str[i] && i < 30; i++) {
			lowerCase[i] = str[i] | 0x20;
		}
		lowerCase[i] = 0;
	}
	int compare(const Contact* A, const Contact* B) { 
		return strcmp(A->name, B->name);
	}

	long long getLongLong(long long min, long long max, const char* valueName) {
		long long val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				if (!valid(min, max, val)) {
					cout << "Invalid " << valueName << "!" << endl
						<< "The " << valueName << " must be between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}

	


	bool yes() {
		char ch;
		ch = cin.get();// make sure buffer is clear
		cin.ignore(1000, '\n');
		return ch == 'y' || ch == 'Y';
	}

	void getStr(char* str, int len) {
		cin.getline(str, len, '\n'); //using function of IO stream
	}

	bool valid(long long min, long long max, long long val) {
		return min <= val && val <= max;
	}
}
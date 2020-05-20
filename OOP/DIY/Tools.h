/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is header file of Tools, it contains helper functions prototypes.
*/

#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

namespace sdds
{

void toLowerCase(char* lowerCase, const char* str);

long long getLongLong(long long min, long long max, const char* valueName);

bool yes();

int compare(const struct Contact* A, const struct Contact* B);

void getStr(char* str, int len);

bool valid(long long min, long long max, long long val);
}

#endif
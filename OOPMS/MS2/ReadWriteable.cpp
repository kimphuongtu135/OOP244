/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 23th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "ReadWriteable.h"



using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const ReadWriteable&readwrite){
		readwrite.write(os);
		return os;
	}

	std::istream& operator >>(std::istream& is, ReadWriteable& readwrite) {
		readwrite.read(is);
		return is;
	}

}
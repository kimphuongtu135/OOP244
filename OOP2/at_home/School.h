/*-----------------------
Name: Kim Phuong Tu
Student ID: 148886179
OOP Lab 2- in lab
Date: Sep 19,2019
------------------------*/

#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__
#include "Subject.h"
namespace sdds
{
	struct School
	{
		int m_noOfSubjects;
		Subject* m_subjects;
		char* m_name;
	};
	void read(School&);
	int report(const School&);
	void freeMem(School&);

}
#endif // !

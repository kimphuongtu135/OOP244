/*-----------------------
Name: Kim Phuong Tu
Student ID: 148886179
OOP Lab 2- at home
Date: Sep 20,2019
------------------------*/

#include <iostream>
#include <cstring>
#include "utils.h"
#include "Subject.h"
#include "School.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds
{
	void read(School& Sch)
	{
		char arr[61];
		cout << "Please enter the name of the school:\n> ";
		read(arr, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: ");
		Sch.m_name = new char[strlen(arr) + 1];// make sure it is large enough for copying
		strcpy(Sch.m_name, arr); // calling strcpy function


		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

		Sch.m_subjects = new Subject[Sch.m_noOfSubjects]; // dynamically alocating
		for (int i = 0; i < Sch.m_noOfSubjects; i++)
		{
			cout << i + 1 << ") ------------------------------" <<endl;
			read(Sch.m_subjects[i]);
			

		}
	}

		int report(const School& school)
		{
			cout << school.m_name<<endl; 
			cout << "Subject Enrollments"<<endl;

			int total = 0;
			for (int i = 0; i < school.m_noOfSubjects; i++)
			{
				total += report(school.m_subjects[i]); // calling the report function which we have in subject.cpp
				
			}
			cout << "Total enrollment: " << total << endl;
		
			return total ;
		}

		void freeMem(School& scho)
		{
			delete[] scho.m_name; // we have to delete the school name first.
			for (int i = 0; i < scho.m_noOfSubjects; i++) // loop for free memories
			{
				freeMem(scho.m_subjects[i]); // calling the freeMem function which we have in Subject.cpp
			}
			delete[] scho.m_subjects; // delete the allocated memories for m_subjects
		}

		
	}



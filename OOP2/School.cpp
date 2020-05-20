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
		Sch.m_name = new char[strlen(arr) + 1];
		strcpy(Sch.m_name, arr);


		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

		Sch.m_subjects = new Subject[Sch.m_noOfSubjects];
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
				total += report(school.m_subjects[i]);
				
			}
			cout << "Total enrollment: " << total << endl;
		
			return total ;
		}

		void freeMem(School& scho)
		{
			delete[] scho.m_subjects;
			delete scho.m_name;
			delete &scho.m_noOfSubjects;
		}

		
	}



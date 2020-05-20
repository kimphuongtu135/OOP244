/*-----------------------
Name: Kim Phuong Tu
Student ID: 148886179
OOP Lab 2- at home
Date: Sep 120,2019
------------------------*/



#include <iostream>
#include <cstring>
#include "utils.h"
#include "Subject.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds
{
	void read(char* st)
	{
		cout << "Enter subject name: ";
		read(st, 70, "Name is too long, only 70 chracters allowed!\nRedo Entry: ");

	}

	void read(int& st2)
	{
		cout << "Enter number of sections: ";
		read(st2, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");

	}

	void read(int arr[], int number)
	{
		cout << "Enter the number of students in each one of the " << number << " sections:" << endl;

		for (int i = 0; i < number; i++)
		{
			cout << i + 1 << ": ";
			read(arr[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}
	}

	void read(Subject& Sub)
	{
		char subArr[71];
		read(subArr);
		Sub.m_subjectName = new char[strlen(subArr) + 1]; // allocating the dymanic memories
		strcpy(Sub.m_subjectName, subArr); // using strcpy function for copying

		Sub.m_noOfSections = new int; // allocating the dymanic memories for m_noOfSections
		read(*Sub.m_noOfSections);

		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);
	}



	int report(const Subject& subs)
	{
		int total = 0;
		for (int i = 0; i < *subs.m_noOfSections; i++)
		{
			cout << subs.m_noOfStdsInSecs[i];
			if (i + 1 != *subs.m_noOfSections)
			{
				cout << ",";
			}
			else {
				cout << endl;
			}
			total += subs.m_noOfStdsInSecs[i];
		}
		cout <<subs.m_subjectName << ": " << total << endl;

		return total;

	}

	void freeMem(Subject& sub) // this Function helps to free dynamic memories that we allocated.
	{
		delete[] sub.m_subjectName;
		delete	sub.m_noOfSections;
		delete[] sub.m_noOfStdsInSecs;

	}
}
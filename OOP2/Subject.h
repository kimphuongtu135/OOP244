/*-----------------------
Name: Kim Phuong Tu
Student ID: 148886179
OOP Lab 2- in lab
Date: Sep 19,2019
------------------------*/

#ifndef SDDS_SUBJECT_H__
#define SDDS_SUBJECT_H__
namespace sdds 
{
	struct Subject
	{
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};
	
	void read(char*);
	void read(int&);
	void read(int[], int);
	void read(Subject&);
	int report(const Subject&);
	void freeMem(Subject&);

}
#endif // !

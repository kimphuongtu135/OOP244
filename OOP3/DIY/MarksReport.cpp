/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 30th, 2019
---------------------------*/



#include <iostream>
#include "Mark.h"
#include"MarksReport.h"



#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds
{
	// Function helps to clear the buffer
	void MarksReport::flushKeyboard() const {
		while (cin.get() != '\n');
	}

	ostream& MarksReport::line(int len, char ch) {
		for (int i = 0; i < len; i++, cout << ch);
		return cout;
	}
	// Function helps to set variables in the "ready" state
	void MarksReport::initialize() {
		title[0] = '\0';
		numMark = 0;
		mark = nullptr;
	}

	//Function helps to get value for Mark
	void MarksReport::getMarks() {
		bool success = true;
		while (success == true) {
			cout << "Enter the report Name: ";
			cin.getline(title, 71);

			if (cin.fail()) {						//set the safe empty space for the name
				cin.clear();
				flushKeyboard();
				title[0] = '\0';
			}
			else {
				success = false;
			}
		}
		bool success1 = true;
		while (success1 == true) {
			cout << "Enter the number of marks: ";
			cin >> numMark;

			if (cin.fail())						// set the safe empty space for the marks
			{
				cin.clear();
				flushKeyboard();
				numMark = 0;
			}
			else
			{
				success1 = false;
			}
		}
		mark = new Mark[numMark];			// Dynamic allocation the value of mark



		cout << "Please enter " << numMark << " marks:" << endl;

		flushKeyboard();			// Making sure clear the buffer

		for (int i = 0; i < numMark; i++) {
			mark[i].setEmpty();
			mark[i].set(DSP_LETTER);
			cout<<(i + 1) << ": ";
			while (!mark[i].readName("Subject Name: ", 6) || !mark[i].read("Mark (mark/outof): ")) {
				cout << "Invalid Entry, retry!" << endl;
				mark[i].set(DSP_LETTER);
			}
		}
		cout << "Entry Completed!" << "\n" << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}


		// Function helps to print the Mark
		void MarksReport::print() {
			Mark result;
			result.setEmpty();			// set Empty for result
			double gpa = 0;
			int lowestGrade = mark[0].percent();    //Declerate the lowestGrade
			int highestGrade = mark[0].percent();   //Declerate the highestGrade

			cout << title << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Marks entered:" << endl;

			for (int i = 0; i < numMark; i++) {
				mark[i].display(66) << endl;

				
				if (lowestGrade > mark[i].percent())
				{
					lowestGrade = mark[i].percent();
				}

				
				if (highestGrade < mark[i].percent()) 
				{
					highestGrade = mark[i].percent();
				}

				gpa += mark[i].letterBasedGPA();
			}
			line(70, '-') << endl;
			
			
			//Display the lowest Mark
			result.set(lowestGrade, 100);
			result.set(DSP_PERCENT);
			result.set("Lowest Mark");
			line(30, ' ');
			result.display(36) << endl;
			
			//Display the highest mark
			result.set(highestGrade, 100);
			result.set(DSP_PERCENT);
			result.set("Highest mark");
			line(30, ' ');
			result.display(36) << endl;

			//Display the GPA
			result.set(gpa / numMark, 4);
			result.set(DSP_GPA);
			result.set("GPA");
			line(30, ' ');
			result.display(36) << endl;

		}

		// Function helps to delete the dynamic allocation
		void MarksReport::terminate()
		{
			delete[] mark;
		}


}
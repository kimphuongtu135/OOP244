/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 28th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include<cstring>
#include "Mark.h"




using namespace std;
namespace sdds
{

	void Mark::flushKeyboard() const {
		while (cin.get() != '\n');
	}


	void Mark::set(int diaplayMode) {
		m_displayMode = diaplayMode;

	}

	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;

	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		m_name[0] = '\0';			// set the m_name to empty string
	}

	bool Mark::isEmpty()const {
		if (m_mark == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	int Mark::percent() const {
		int percent;
		percent = (int)(m_mark / m_outOf * 100 + 0.5);
		return percent;
	}

	double Mark::rawValue() const {
		double result;
		result = m_mark / m_outOf;
		return result;
	}

	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			success = false;
		}
		flushKeyboard();
		return success;
	}

	ostream& Mark::display(int width) const {
		if (m_name[0] != '\0') {
			int dot;
			dot = width - strlen(m_name); // checking the empty space
			cout << m_name;

			for (int i = 0; i < dot; i++) {
				cout << '.';
			}
		}

		if (isEmpty())
		{
			cout << "Empty Mark object!";

		}
		else
		{
			switch (m_displayMode)
			{
			case DSP_RAW:
				cout << fixed << setprecision(2) << rawValue(); // take two digit after the point
				break;
			case DSP_PERCENT:
				cout << "%" << percent();
				break;
			case DSP_ASIS:
				cout << fixed << setprecision(1) << m_mark << "/" << m_outOf;
				break;
			case DSP_UNDEFINED:
				cout << "Display mode not set!";
				break;
			case DSP_LETTER:
				prnLetter();
				break;
			case DSP_GPA:
				double value;
				value = GPA();
				cout << fixed << setprecision(1) << value;
				break;
			default:
				cout << "Invalid Mark Display setting!" << endl;
				break;
			}

		}
		return cout;
	}

	void Mark::prnLetter() const {
		if (m_mark != 0) {
			int value = percent();			// using value of percent() function as value of variable
			if (value >= 0 && value <= 49) {
				cout << "F";
			}
			else if (value >= 50 && value <= 54) {
				cout << "D";
			}
			else if (value >= 55 && value <= 59) {
				cout << "D+";
			}
			else if (value >= 60 && value <= 64) {
				cout << "C";
			}
			else if (value >= 65 && value <= 69) {
				cout << "C+";
			}
			else if (value >= 70 && value <= 74) {
				cout << "B";
			}
			else if (value >= 75 && value <= 79) {
				cout << "B+";
			}
			else if (value >= 80 && value <= 89) {
				cout << "A";
			}
			else if (value >= 90 && value <= 100) {
				cout << "A+";
			}
			else if (value > 100) {
				cout << "?";
			}
		}
		else {

		}
	}

	void Mark::set(const char* name) {
		strcpy(m_name, name);
	}
	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);
		set(rawMark, outof);
	}
	bool Mark::readName(const char* prompt, int maxLen) {
		cout << prompt;
		if (maxLen > 50) {
			maxLen = 50;
		}
		char* name;
		name = new char[maxLen + 1];			// dynamic allocation value for name
		cin.getline(name, maxLen + 1);

		if (cin.fail()) {
			cin.clear();
			flushKeyboard();
			m_name[0] = '\0';
			return false;
		}
		strcpy(m_name, name);
		delete[] name;
		return true;
	}

	void Mark::changeOutOf(int value) {
		m_mark = ((double)value / m_outOf) * m_mark;
		m_outOf = value;

		if (value < 1) {
			setEmpty();
		}
	}

	double Mark::GPA()const {
		double gpa;
		gpa = rawValue() * 4;
		return gpa;
	}
	double Mark::letterBasedGPA()const {

		int value = percent();
		double based;
		if (value >= 0 && value <= 49) {
			based = 0.0;
		}
		else if (value >= 50 && value <= 54) {
			based = 1.0;
		}
		else if (value >= 55 && value <= 59) {
			based = 1.5;
		}
		else if (value >= 60 && value <= 64) {
			based = 2.0;
		}
		else if (value >= 65 && value <= 69) {
			based = 2.5;
		}
		else if (value >= 70 && value <= 74) {
			based = 3.0;
		}
		else if (value >= 75 && value <= 79) {
			based = 3.5;
		}
		else if (value >= 80 && value <= 89) {
			based = 4.0;
		}
		else if (value >= 90 && value <= 100) {
			based = 4.0;
		}
		return based;
	}

}







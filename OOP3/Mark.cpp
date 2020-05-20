/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 26th, 2019
---------------------------*/


#include <iostream>
#include "Mark.h"
	

#define _CRT_SECURE_NO_WARNINGS

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
	}

	bool Mark::isEmpty()const {
		if (m_mark == -1 && m_outOf == 100 && m_displayMode == DSP_UNDEFINED) {
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

	ostream& Mark::display() const {
		if (isEmpty())
		{
			cout << "Empty Mark object!";
			
		}
		else
		{
			switch (m_displayMode)
			{
			case DSP_RAW:
				cout << rawValue();
				break;
			case DSP_PERCENT:
				cout << "%" << percent();
				break;
			case DSP_ASIS:
				cout << m_mark << "/" << m_outOf;
				break;
			case DSP_UNDEFINED:
				cout << "Display mode not set!";
				break;

			default:
				cout << "Invalid Mark Display setting!" << endl;
				break;
			}
		
		}
		return cout;
	}
}

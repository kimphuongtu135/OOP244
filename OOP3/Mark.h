#include <iostream>
#ifndef SDDS_MARK_H__
#define SDDS_MARK_H__
using namespace std;
namespace sdds
{
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

	class Mark {
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushKeyboard() const;

	public:
		void set(int diaplayMode);
		void set(double mark, int =1);
		void setEmpty();
		bool isEmpty()const;
		int percent() const;
		double rawValue()const;
		bool read(const char* prompt);
		ostream& display() const;

	};

};
#endif // !


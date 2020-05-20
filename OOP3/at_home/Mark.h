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
	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;
	

	class Mark {
		char m_name[52];
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushKeyboard() const;
		void prnLetter() const;

	public:
		void set(int diaplayMode);
		void set(double mark, int = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent() const;
		double rawValue()const;
		bool read(const char* prompt);
		ostream& display(int width = 55) const;


		void set(const char* name);
		void set(const char* name, double rawMark, int outof= 1);
		bool readName(const char* prompt, int maxLen=50);
		void changeOutOf( int value);
		double GPA()const;
		double letterBasedGPA() const;
		
	};

};
#endif // !


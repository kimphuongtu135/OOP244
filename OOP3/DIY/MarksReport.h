#ifndef SDDS_MARKREPORT_H__
#define SDDS_MARKREPORT_H__
#include"Mark.h"
using namespace std;
namespace sdds
{
	class MarksReport {
		int numMark;
		Mark* mark;
		char title[71];
		void flushKeyboard() const;
		ostream& line(int len, char ch);
	public:
		void initialize();
		void getMarks();
		void print();
		void terminate();
	};
}
#endif // !
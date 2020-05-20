// Pen.h
#include "WriteInstrument.h"
#ifndef SDDS_PEN_H__
#define SDDS_PEN_H__
#define INK_MAX 50



using namespace std;
namespace sdds
{
	class Pen :public WriteInstrument {
		char* style;
		int ink;
	public:
		Pen();
		~Pen();
		Pen(const char*, int);
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual ostream& display(ostream& os) const;
	};
}
#endif // !
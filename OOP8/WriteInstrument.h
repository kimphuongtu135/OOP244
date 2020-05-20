// WriteInstrument.h
#include <iostream>
#ifndef SDDS_WRITEINSTRUMENT_H__
#define SDDS_WRITEINSTRUMENT_H__



using namespace std;
namespace sdds
{
	class WriteInstrument {
	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char*) = 0;
		virtual void refill(int) = 0;
		virtual bool filled() const = 0;
		virtual ostream& display(ostream& os) const = 0;

	};


}
#endif // !

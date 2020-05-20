// Pencil.h
#include "WriteInstrument.h"
#ifndef SDDS_PENCIL_H__
#define SDDS_PENCIL_H__
#define HB_MAX 2
#define GRAPHITE_MAX 100


using namespace std;
namespace sdds
{
	class Pencil :public WriteInstrument {
		char scale[HB_MAX+1];
		int graphite;
	public:
		Pencil();
		Pencil(const char*, int);
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual ostream& display(ostream& os) const;
	};
}
#endif // !
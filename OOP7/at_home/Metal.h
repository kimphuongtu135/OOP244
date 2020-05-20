// Metal.h
#include <iostream>
#include "Ore.h"
#ifndef SDDS_METAL_H__
#define SDDS_METAL_H__

using namespace std;
namespace sdds 
{
	const double DEFAULT_MOHS = 2.5;
	const int NAME_LEN = 10;

class Metal : public Ore {
	char* name;
	double mohs;
public:
	Metal();
	~Metal();
	Metal(double, int, const char*, const char*, double);
	void refine();
	ostream& display(ostream& os)const;
	istream& input(istream& is);
};
ostream& operator <<(ostream& os, const Metal& met);
istream& operator >> (istream& is, Metal& met);

}
#endif // !
// Ore.h
#include <iostream>
#ifndef SDDS_ORE_H__
#define SDDS_ORE_H__



using namespace std;
namespace sdds
{

	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;
	class Ore {
		double weight;
		int purity;
		char classification[CLASS_LEN + 1];
	public:
		Ore();
		Ore(double, int, const char* classification = "Unknown");
		bool refine();
		ostream& display(ostream& os)const;
		istream& input(istream& is);
	};
	ostream& operator <<(ostream& os, const Ore& ore);
	istream& operator >>(istream& os, Ore& ore);
}

#endif // !


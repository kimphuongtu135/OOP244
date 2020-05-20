#include <iostream>
#ifndef SDDS_FLOWER_H__
#define SDDS_FLOWER_H__



using namespace std;
namespace sdds
{
	const int  NAME_MAX_LEN = 25;
	const int	COL_MAX_LEN = 15;
	class Flower {
		char* f_name;
		char* f_colour;
		double f_price;
		
	public:
		Flower();
		Flower(const char*, const char*, double);
		const char* name() const; 
		const char* colour()const;
		double price()const;
		bool isEmpty()const;
		void setEmpty();
		void setName(const char* prompt);
		void setColour(const char* prompt);
		void setPrice(const char* prompt);
		void setFlower();
		ostream& display() const;
		~Flower();


	};

}
#endif // !


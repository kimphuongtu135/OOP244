#include <iostream>
#ifndef SDDS_BOUQUET_H__
#define SDDS_BOUQUET_H__
#include"Flower.h"

using namespace std;
namespace sdds
{
#define MESS_MAX_LEN 30
#define MAX_FLOWERS 3

	class Bouquet {
		double b_price;
		char* b_message;
		Flower* b_flower;
		int b_flowerCount;

	public:
		Bouquet();
		Bouquet(const Flower*,int =MAX_FLOWERS , const char* ="Congratulations");
		~Bouquet();

		const char* message()const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setMessage(const char* prompt);
		void discardBouquet();
		void arrangeBouquet();
		ostream& display() const;

	};

}
#endif // !

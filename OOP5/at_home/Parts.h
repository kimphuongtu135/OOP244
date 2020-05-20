// Parts.h
// Parts.h
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/
#ifndef SDDS_ARMS_H__
#define SDDS_ARMS_H__
#define MIN_FORCE 50
#define MIN_SPEED 25


using namespace std;
namespace sdds
{
	class Arms {
		int force;
	public:
		Arms();
		Arms(int);
		int getForce()const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);


	};

	class Legs {
		int speed;
	public:
		Legs();
		Legs(int);
		int getSpeed()const;
		Legs& operator-=(int);
	};

	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);
}
#endif // !






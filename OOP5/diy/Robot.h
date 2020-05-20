// Robot.h
// Robot.h
// Robot.h
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/
#include "Parts.h"
#ifndef SDDS_ROBOT_H__
#define SDDS_ROBOT_H__
#define NICK_MAX_LEN 10


using namespace std;
namespace sdds
{
	class Robot {
		char nickname[NICK_MAX_LEN + 1];
		int durability;
		Arms arms;
		Legs legs;
	public:
		Robot();
		Robot(const char*, int, int, int);
		ostream& display()const;
		Arms getArms()const;
		Legs getLegs()const;
		operator bool()const;
		Robot& operator-=(int);
	};
	void box(Robot&, Robot&);

}
#endif // !

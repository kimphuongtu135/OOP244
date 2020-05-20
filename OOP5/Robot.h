// Robot.h
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
		Arms arms ;
	public:
		Robot();
		Robot(const char* ,int ,int);
		ostream& display()const;
		operator bool()const;

	};

}
#endif // !

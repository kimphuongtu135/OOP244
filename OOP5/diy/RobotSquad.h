// RobotSquad.h
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/
#ifndef SDDS_ROBOTSQUAD_H__
#define SDDS_ROBOTSQUAD_H__
#include "Robot.h"

using namespace std;
namespace sdds
{
	class RobotSquad {
		char name[11];
		Robot* roster;
		int count;
	public:
		RobotSquad();
		RobotSquad(const char* );
		RobotSquad& operator+=(Robot);
		RobotSquad&  operator--();
		ostream& display()const;
		Robot* getRoster()const;
		~RobotSquad();
	};
	
}
#endif // !
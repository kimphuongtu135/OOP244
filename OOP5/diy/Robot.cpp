// Robot.cpp
// Robot.cpp
// Robot.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parts.h"
#include "Robot.h"

using namespace std;
namespace sdds {

	//Set the empty state 
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
		legs = 0;
	}

	Robot::Robot(const char* nick, int num, int sped, int dura) {

		//Set value for nickname
		if (nick == nullptr || nick[0] == '\0') {
			nickname[0] = '\0';
			durability = 0;
			legs = 0;
		}

		else {
			//Set the value for nickname
			if (strlen(nick) > NICK_MAX_LEN)

				strncpy(nickname, nick, NICK_MAX_LEN);

			else
				strcpy(nickname, nick);


			//Set the value for durability
			if (dura < 1)
				durability = 100;
			else
				durability = dura;

			//Set the value for arms's force
			arms = Arms(num);
			legs = Legs(sped);
		}
	}
	ostream& Robot::display()const {
		if (  durability == 0) {
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;

		}
		return cout;
	}
	// Return the value of arms class
	Arms Robot::getArms()const {
		return arms;
	}

	Legs Robot::getLegs()const {
		return legs;
	}

	Robot::operator bool()const {
		if (nickname[0] == '\0' || durability == 0)
			return true;
		else
			return false;
	}

	Robot& Robot::operator-=(int num) {
		durability -= num;
		if (durability < 1)
			durability = 0;
		return *this;

	}

	void box(Robot & robot1, Robot & robot2) {

		cout << "Attempting to begin a Robot boxing match" << endl;

		if (robot1.operator bool() != true && robot2.operator bool() != true)
		{
			cout << "Both participants are operational... beginning the bout" << endl;

			while (robot1.operator bool() != true && robot2.operator bool() != true)
			{
				if (robot1.getLegs() > robot2.getLegs())		//Compare which robot is faster than another one
				{
					robot2.operator-= (robot1.getArms().getForce());
					if (robot2.operator bool() != true)
						robot1.operator-= (robot2.getArms().getForce());
				}
				else {
					robot1.operator-= (robot2.getArms().getForce());
					if (robot1.operator bool() != true)
						robot2.operator-= (robot1.getArms().getForce());
				}
			}
			//Comparing which robot is KO first
			if (robot1.operator bool() != true || robot2.operator bool() != true)
				cout << "The bout has concluded... the winner is: " << endl;

			//Finding the winner and display the information of winner
			if (robot1.operator bool() != true)
				robot1.display();
			else
				robot2.display();
		}
		else
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
	}

}


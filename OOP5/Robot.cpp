// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Parts.h"
#include "Robot.h"

using namespace std;
namespace sdds {
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;

	}
	Robot::Robot(const char* nick, int num, int dura) {
		\
			//Set value for nickname
			if (nick == nullptr || nick[0] == '\0') {
				 nickname[0] = '\0';
				durability = 0;
			}
			else {
				if (strlen(nick) > NICK_MAX_LEN) {
					//nickname[strlen(nick)+1];
					strncpy(nickname, nick, NICK_MAX_LEN);
				}
				else {
					strcpy(nickname, nick);
				}

				//Set the value for durability
				if (dura < 1)
					durability = 100;
				else
					durability = dura;

				//Set the value for arms's force
				arms = Arms(num);
			}
	}
	ostream& Robot::display()const {
		if (nickname[0] == '\0' && durability == 0) {
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
		}
		return cout;
	}
	Robot::operator bool()const {
		if (nickname[0] == '\0' || durability == 0)
			return true;
		else
			return false;
	}



}
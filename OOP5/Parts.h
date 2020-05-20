// Parts.h#include <iostream>
#ifndef SDDS_ARMS_H__
#define SDDS_ARMS_H__
#define MIN_FORCE 50


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
}
#endif // !





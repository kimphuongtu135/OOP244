#include <iostream>
#include "PubRecord.h"
#ifndef SDDS_MAGAZINE_H__
#define SDDS_MAGAZINE_H__

using namespace std;
namespace sdds
{
	class Magazine :public PubRecord {
		int volume;
		int noIssue;
	public:
		Magazine();
		~Magazine();
		Magazine(const Magazine&);
		Magazine& operator= (const Magazine&);
		 char recID()const ;
		 void checkIn() ;
		 void checkOut() ;
		 std::istream& read(std::istream& is = std::cin) ;
		 std::ostream& write(std::ostream& os = std::cout) const ;
	};
}

#endif // !


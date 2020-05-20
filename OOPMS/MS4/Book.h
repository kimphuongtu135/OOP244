#include <iostream>
#include "Date.h"
#include "PubRecord.h"
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

using namespace std;
namespace sdds
{
	class Book :public PubRecord {
		long long int ISBN;
		int id;
		Date date;
	public:
		Book();
		~Book();
		Book(const Book&);
		Book& operator= (const Book&);
		char recID()const ;
		int memberId()const;
		 void checkIn() ;
		 void checkOut();
		 std::istream& read(std::istream& is = std::cin) ;
		 std::ostream& write(std::ostream& os = std::cout) const;
	};
}

#endif // !


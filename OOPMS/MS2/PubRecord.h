#include <iostream>
#include "ReadWriteable.h"
#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__
#define SDDS_CONSOLE 13
#define SDDS_FILE  4

using namespace std;
namespace sdds
{
	class PubRecord:public ReadWriteable {
		char* nameOfPub;
		int noOfPub;
		int type;
	protected:
		void name(const char*);
		const char* name()const;

	public:
		virtual char recID()const;
		PubRecord();
		~PubRecord();
		PubRecord& operator=(const PubRecord& );
		void mediaType(int);
		int mediaType()const;
		int shelfNo()const;
		int readShelfNo();
		bool operator==(char)const;
		bool operator==(const char*)const;
		operator bool()const;

	};
}


#endif // !



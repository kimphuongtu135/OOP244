// Figurine.h
#ifndef SDDS_FIGURINE_H__
#define SDDS_FIGURINE_H__
#define MAX_NAME_LEN 20
#define DEFAULT_PRICE 25.25


using namespace std;
namespace sdds
{
	class Figurine{
		char name[MAX_NAME_LEN+1];
		char* pose;
		double price;
	public:
		Figurine();
		Figurine(const char*,const char*,double);
		Figurine(const Figurine&);
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		ostream& display()const;
		operator bool()const;
		~Figurine();
};
}
#endif // !

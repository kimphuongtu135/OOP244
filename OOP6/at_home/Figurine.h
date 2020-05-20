// Figurine.h
#ifndef SDDS_FIGURINE_H__
#define SDDS_FIGURINE_H__
#define MAX_NAME_LEN 20
#define DEFAULT_PRICE 25.25


using namespace std;
namespace sdds
{
	class Figurine {
		char name[MAX_NAME_LEN + 1];
		char* pose;
		double price;
		bool copy;
	public:
		Figurine();
		Figurine(const char*, const char*, double);
		Figurine(const Figurine&);
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		ostream& display()const;
		operator bool()const;
		~Figurine();
		Figurine& operator=(const Figurine&);
		bool isCopy() const;
		const char*	getName()const;
		const char* getPose()const;
		double getPrice()const;
		
	};
	bool operator==(const Figurine&, const Figurine&);
}
#endif // !

#include <iostream>
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#define MAX_MENU_ITEMS 20


using namespace std;
namespace sdds
{


	class Menuitem {
		char* title;
		Menuitem();
		~Menuitem();
		const char* getTitle()const;
		friend class Menu;
		Menuitem(const char*);
		void setName(const char* );
		Menuitem(const Menuitem& source) = delete;
		Menuitem& operator=(const Menuitem& source) = delete;
		operator bool()const;
		operator const char* ()const;
		ostream& display(std::ostream& os)const;
	};

	class Menu {
		Menuitem name;
		Menuitem* arr[MAX_MENU_ITEMS];
		int number;
		
		
	public:
		Menu();
		Menu(const char*);
		~Menu();
		ostream& display(std::ostream& os)const;
		ostream& display1(std::ostream& os)const;
		int getSelection();
		int operator~();
		operator bool()const;
		operator unsigned int()const;
		int getNumber();
		void addMenuitem(const char*);
		const char* operator[](int i)const;


	};

	std::ostream& operator<<(std::ostream& os,const Menu&  );
	Menu& operator << (Menu& , const char* Menuitem);
}

#endif // !


/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 14th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Menu.h"
#include "Utils.h"



using namespace std;
namespace sdds
{
	Menuitem::Menuitem() {
		title = nullptr;
	}

	Menuitem::Menuitem(const char* title1) {
		title = new char[strlen(title1) + 1];
		strcpy(title, title1);
	}

	Menuitem::~Menuitem() {
		delete[] title;
	}

	const char* Menuitem::getTitle()const {
		return title;
	}


	void Menuitem::setName(const char* name) {
		if (title != nullptr)
			delete[] title;
		else {
			title = new char[strlen(name) + 1];
			strcpy(title, name);
		}
	}
	Menu::Menu() {
		//Set variable in safe empty state
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			arr[i] = nullptr;
		}
		number = 0;
	}

	Menu::Menu(const char* title1) {
		//Set value for title
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			arr[i] = nullptr;
		}
		number = 0;

		name.title = new char[strlen(title1) + 1];
		strcpy(name.title, title1);
		name.title[strlen(title1)] = '\0';
		//arr = new Menuitem[MAX_MENU_ITEMS];
		for (int i = 0; i < number; i++) {
			arr[i] = new Menuitem();
		}

		number = 0;
	}

	Menu::~Menu() {
		for (int i = 0; i < number; i++) {
			delete arr[i];
		}
	}

	Menuitem::operator bool()const {
		return !(title == nullptr || title[0] == '\0');
	}

	Menuitem::operator const char* ()const {
		return title;
	}
	ostream& Menuitem::display(std::ostream & os)const {
		os << title;
		return os;
	}

	ostream& Menu::display(std::ostream & os)const {
		if (name.title != nullptr)
			name.display(os);
		return os;
	}

	ostream& Menu::display1(std::ostream & os)const {
		if (name.title != nullptr)
			display(os) << ":" << endl;
		for (int i = 0; i < number; i++) {

			os << " " << i + 1 << "- " << arr[i]->getTitle() << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return cout;
	}

	int Menu::getSelection() {
		int choice;
		display1(std::cout);
		read(choice, 0, number, "Invalid Selection, try again: ");
		return choice;
	}

	int Menu::operator~() {
		return getSelection();

	}

	Menu::operator bool()const {
		if (number == 0)
			return false;
		else
			return true;
	}

	Menu::operator unsigned int()const {
		return number;
	}

	int Menu::getNumber() {
		return number;
	}

	void Menu::addMenuitem(const char* menuitem) {
		Menuitem* menuitem1;
		menuitem1 = new Menuitem(menuitem);
		arr[number] = menuitem1;
		number++;

	}

	const char* Menu::operator[](int i)const {
		if (i < number)
			return arr[i]->getTitle();
		else
			return arr[0]->getTitle();
	}



	std::ostream& operator<<(std::ostream & os, const Menu & menu1) {
		menu1.display(os);
		return os;
	}
	Menu& operator << (Menu & menu1, const char* Menuitem) {
		if (menu1.getNumber() < MAX_MENU_ITEMS)
			menu1.addMenuitem(Menuitem);
		return menu1;
	}

}



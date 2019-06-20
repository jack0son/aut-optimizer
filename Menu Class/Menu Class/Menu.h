#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <vector>
#include <string>
#include "MenuItem.h"

using namespace std;

class Menu
{
private:
	string heading;
	vector <MenuItem> item;
	int length;
public:
	Menu();
	Menu(string heading);
	~Menu();

	void setHeading(string h);
	string getHeading(void);

	int addItem(string name, void (*function)(void));
	int removeItem(int index);
	int removeItem(string name);
	vector<MenuItem> getItem();
	void updateLength();
	
	int printMenu();
	int useMenu();
};

#endif
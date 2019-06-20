#include "Menu.h"

using namespace std;
//const / dest
Menu::Menu(string heading)
{
	setHeading(heading);
	updateLength();
}
Menu::Menu()
{
	updateLength();
}
Menu::~Menu()
{
}

//heading control
void Menu::setHeading(string h)
{
	heading = h;
}
string Menu::getHeading(void)
{
	return heading;
}

//item vector control
int Menu::addItem(string name, void (*function)(void))
{
	MenuItem temp;
	temp.setIndex(item.size());
	temp.setName(name);
	temp.setFunction(function);
	item.push_back(temp);
	updateLength();
	return 1;
}
int Menu::removeItem(int index)
{
	item.erase(item.begin()+index);
	updateLength();
	return 1;
}
int Menu::removeItem(string name)
{
	int i;
	for(i = 0; i < length; i++)
	{
		if(name == item[i].getName())
		{
			break;
		}
	}
	if(i == length)
	{
		return 0;
	}
	removeItem(i);
	updateLength();
	return 1;
}
vector<MenuItem> Menu::getItem()
{
	return item;
}
void Menu::updateLength()
{
	length = item.size();
}

//using the menu
int Menu::printMenu()
{
	if(!length)
	{
		return 0;
	}
	cout << heading << endl;
	for(int i=0; i < length; i++)
	{
		cout << "\t" << i <<  ": " << item[i].getName() << endl;
	}
	return 1;
}

int Menu::useMenu()
{
	int choice;
	do
	{
		if(!printMenu()) return 0;
		cout << "Choice: ";
		cin >> choice;
	}
	while(choice < 0 || choice > length);
	item[choice].useFunction();

	return 1;
}


	
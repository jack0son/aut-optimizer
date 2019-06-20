#include "MenuItem.h"

using namespace std;

//index control
int MenuItem::setIndex(int index)
{
	itemIndex = index;
	return 1;
}
int MenuItem::getIndex()
{
	return itemIndex;
}

//name control
int MenuItem::setName(string name)
{
	itemName = name;
	return 1;
}
string MenuItem::getName()
{
	return itemName;
}

//function pointer control
int MenuItem::setFunction(void (*function)(void))
{
	itemFunction = function;
	return 1;
}
void MenuItem::useFunction()
{
	itemFunction();
}

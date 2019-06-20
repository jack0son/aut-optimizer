#ifndef MENUITEM_H_
#define MENUITEM_H_
#include <vector>
#include <string>

class MenuItem
{
private:
	int itemIndex;
	std::string itemName;
	void (*itemFunction)(void);
public:
	int setIndex(int index);
	int getIndex();

	int setName(std::string name);
	std::string getName();

	int setFunction(void (*function)(void));
	void useFunction();
};

#endif
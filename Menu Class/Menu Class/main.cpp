#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
using namespace std;

void sayLol()
{
	cout << "Lol\n";
}
void sayBums()
{
	cout << "Bums\n";
}

int main()
{
	Menu menu("fun stuff");
	menu.addItem("Lol", &sayLol);
	menu.addItem("Bums", &sayBums);
	menu.useMenu();
	menu.removeItem(0);
	menu.useMenu();
	menu.removeItem("Bums");
	menu.useMenu();


	system("pause");
	
	return 0;
}
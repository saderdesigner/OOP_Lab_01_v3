#pragma once
#include "Menu.h"


void ShowMenu() {
	cout << "CHON MENU" << endl;
	cout << "1. Ingredent Manager" << endl;
	cout << "2. Dish Manager" << endl;
	cout << "3. Order Manager" << endl;
	cout << "4. Table Manager" << endl;

	cout << "0. Exit" << endl;
}

int SelectMenu() {
	int option = 0;
	cin >> option;
	cin.ignore();
	return option;
}

void GenarateMenu() {
	
	bool stop = false;
	int option;

	while (!stop)
	{
		ShowMenu();
		option = SelectMenu();
		switch (option)
		{
		case 1:
		{
			IngredentManager();
			break;
		}
		case 2:
		{
			DishManager();
			break;
		}
		case 3:
		{
			OrderManager();
			break;
		}
		case 4:
		{
			TableManager();
			break;
		}
		case 0:
		{
			stop = true;
			break;
		}
		default:
			break;
		}	
	}
	
}





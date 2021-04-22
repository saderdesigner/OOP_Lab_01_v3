#include "IngredentController.h"

vector<Ingredent> Store::vIngredent;

void IngredentManager() {
	bool stop = false;
	while (!stop)
	{
		cout << "________Ingredent Manager" << endl;
		cout << "\t|____1. Create Ingredent" << endl;
		cout << "\t|____2. Read Ingredent" << endl;
		cout << "\t|____3. Update Ingredent" << endl;
		cout << "\t|____4. Delete Ingredent" << endl;
		cout << "\t|____5. Auto generate Ingredents" << endl;
		cout << "\t|____6. Show list Ingredents" << endl;
		cout << "\t|____0. Back" << endl;

		int option;
		cin >> option;
		cin.ignore();
		switch (option)
		{
			// Create Ingredent
		case 1:
		{
			CreateIngredent();
			break;
		}
		// Read Ingredent
		case 2:
		{
			ReadIngredent();
			break;
		}
		// Update Ingredent
		case 3:
		{
			printVector(Store::vIngredent);
			UpdateIngredent();
			break;
		}
		// Delete Ingredent
		case 4:
		{
			printVector(Store::vIngredent);
			DeleteIngredent();
			break;
		}
		// Auto generate Ingredents
		case 5:
		{
			GenerateListIngredent();
			printVector(Store::vIngredent);
			break;
		}
		// Show list Ingredents
		case 6:
		{
			printVector(Store::vIngredent);
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

void CreateIngredent() {
	string name, unit;
	int qty;
	cout << "Input Name:";
	getline(cin, name);
	cout << "Input Measured Unit: ";
	getline(cin, unit);
	cout << "Input Quantity: ";
	cin >> qty;
	cin.ignore();


	Ingredent i = Ingredent(name, unit, qty);

	cout << i << endl;

	Store::vIngredent.push_back(i);

	cout << "\nCreated" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
}

void ReadIngredent()
{
	cout << "Read Ingredent" << endl;
	string name;
	cout << "Input Ingredent Name: ";
	getline(cin, name);

	auto it = find_if(Store::vIngredent.begin(), Store::vIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });

	if (it != Store::vIngredent.end()) {
		(*it).print("all");
	}
	else {
		cout << "Ingredent " << name << " not found!" << endl;
	}
	return;
}

void UpdateIngredent() {
	string name;
	cout << "Input Ingredent name to update: ";
	getline(cin, name);

	auto it = find_if(Store::vIngredent.begin(), Store::vIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });
	if (it != Store::vIngredent.end()) {
		(*it).inputAndupdate();
	}
	else {
		cout << "Ingredent " << name << " not found!" << endl;
	}
}

void DeleteIngredent()
{
	string name;
	cout << "Input Ingredent name to delete: ";
	getline(cin, name);


	auto it = find_if(Store::vIngredent.begin(), Store::vIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });

	/*
	** inActive Dish, Meal before delete ingredent
	*/
	for (auto it = Store::vDish.begin(); it != Store::vDish.end() ; it++) 
	{
		if ((*it).hasIngredentName(name)) {
			(*it).setIsActive(false);
		}
	}

	for (auto it = Store::vMeal.begin(); it != Store::vMeal.end(); it++)
	{
		if ((*it).hasIngredentName(name)) {
			(*it).removeDish(name);
		}
	}

	Store::vIngredent.erase(it);
}

void GenerateListIngredent()
{
	int lastID = 0;
	if (!Store::vIngredent.empty()) {
		lastID = static_cast<int>(Store::vIngredent.size());
	}
	Ingredent w[10];
	string name, measuredUnit;
	int qty;

	for (int i = 0; i < 10; i++) {
		name = "i" + to_string(lastID + i + 1);
		qty = rand() % 1000 + 1;
		w[i] = Ingredent(name, "kg", qty);

		Store::vIngredent.push_back(w[i]);
	}
}
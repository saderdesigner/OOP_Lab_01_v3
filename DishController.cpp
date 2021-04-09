#include "DishController.h"

vector<Dish> Store::vDish;

void DishManager() {
	bool stop = false;
	while (!stop)
	{
		cout << "________Dish Manager" << endl;
		cout << "\t|____1. Create Dish" << endl;
		cout << "\t|____2. Read Dish" << endl;
		cout << "\t|____3. Update Dish" << endl;
		cout << "\t|____4. Delete Dish" << endl;
		cout << "\t|____5. Auto generate Dishes" << endl;
		cout << "\t|____6. Show Disabled Dishes" << endl;
		cout << "\t|____7. Show Active Dishes" << endl;
		cout << "\t|____8. Add Ingredent to Dish" << endl;
		cout << "\t|____0. Back" << endl;

		int option;
		cin >> option;
		cin.ignore();
		switch (option)
		{
			// Create Dish
		case 1:
		{
			CreateDish();
			break;
		}
		// Read Dish
		case 2:
		{
			ReadDish();
			break;
		}
		// Update Dish
		case 3:
		{
			printVector(Store::vDish);
			UpdateDish();
			break;
		}
		// Delete Dish
		case 4:
		{
			printVector(Store::vDish);
			DeleteDish();
			break;
		}
		// Auto generate Dishes
		case 5:
		{
			GenerateListDish();
			printVector(Store::vDish);
			break;
		}
		// Show Disabled Dishes
		case 6:
		{
			cout << "________ Show Disabled Dishes ________" << endl;
			printVector(Store::vDish, "disable");
			break;
		}
		// Show Active Dishes
		case 7:
		{
			cout << "________ Show Active Dishes ________" << endl;
			printVector(Store::vDish, "active");
			break;
		}
		// Add Ingredent to Dish
		case 8:
		{
			AddIngredentToDish();
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

void CreateDish() {
	string name;
	int qty, id;
	cout << "Input Measured Unit: ";
	cin >> id;
	cin.ignore();
	cout << "Input Name:";
	getline(cin, name);
	cout << "Input Quantity: ";
	cin >> qty;
	cin.ignore();


	Dish i = Dish(id, name, qty);

	Store::vDish.push_back(i);

	cout << "\nCreated" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
}

void ReadDish()
{
	cout << "Read Dish" << endl;
	int id;
	cout << "Input Dish ID: ";
	cin >> id;
	cin.ignore();

	auto it = find_if(Store::vDish.begin(), Store::vDish.end(), [&id](Dish& obj) {return obj.getId() == id; });

	if (it != Store::vDish.end()) {
		(*it).print("all");
	}
	else {
		cout << "Dish ID " << id << " not found!" << endl;
	}
	return;
}

void UpdateDish() {
	int id;
	cout << "Input Dish ID to update: ";
	cin >> id;
	cin.ignore();

	auto it = find_if(Store::vDish.begin(), Store::vDish.end(), [&id](Dish& obj) {return obj.getId() == id; });
	if (it != Store::vDish.end()) {
		(*it).inputAndupdate();
	}
	else {
		cout << "Dish ID " << id << " not found!" << endl;
	}
}

void DeleteDish()
{
	int id;
	cout << "Input Dish name to delete: ";
	cin >> id;
	cin.ignore();


	auto it = find_if(Store::vDish.begin(), Store::vDish.end(), [&id](Dish& obj) {return obj.getId() == id; });

	/*
	** deactive Dish, Meal before delete Dish
	*/

	Store::vDish.erase(it);
}

void GenerateListDish()
{
	int lastID = 1000;
	if (!Store::vDish.empty()) {
		lastID = (*(Store::vDish.end() - 1)).getId();
	}
	Dish w[10];
	string name;
	int qty, id;

	for (int i = 0; i < 10; i++) {

		id = lastID + i + 1;
		name = "Dish " + to_string(id);
		qty = rand() % 10 + 1;

		w[i] = Dish(id, name, qty);

		Store::vDish.push_back(w[i]);
	}
}

void AddIngredentToDish()
{
	int id, qty;
	string name;

	printVector(Store::vDish);
	cout << "Input Dish ID: (or Input `0` to exit): ";
	cin >> id;
	cin.ignore();
	if (id == 0) {
		return;
	}

	auto itDish = find_if(Store::vDish.begin(), Store::vDish.end(), [&id](Dish& obj) {return obj.getId() == id; });
	while (itDish == Store::vDish.end())
	{
		cout << "Dish ID " << id << " not found! Please try again! (or Input `0` to exit)" << endl;
		cout << "Input Dish ID: ";
		cin >> id;
		cin.ignore();
		if (id == 0) {
			return;
		}

		itDish = find_if(Store::vDish.begin(), Store::vDish.end(), [&id](Dish& obj) {return obj.getId() == id; });
	}

	printVector(Store::vIngredent);
	cout << "Input ingredent name: ";
	getline(cin, name);
	if (name == "0") {
		return;
	}

	auto itIngredent = find_if(Store::vIngredent.begin(), Store::vIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });
	while (itIngredent == Store::vIngredent.end())
	{
		cout << "Ingredent " << id << " not found! Please try again! (or Input `0` to exit)" << endl;
		cout << "Input ingredent name: ";
		getline(cin, name);
		if (name == "0") {
			return;
		}

		itIngredent = find_if(Store::vIngredent.begin(), Store::vIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });
	}

	cout << "Input amount of Ingredent to be added (1 - " << floor((*itIngredent).getQuantity() / (*itDish).getQty()) << " ) (or Input `0` to exit): ";
	cin >> qty;
	cin.ignore();
	if (qty == 0) {
		return;
	}

	while (qty * (*itDish).getQty() > (*itIngredent).getQuantity())
	{
		cout << "Invalid input. Please try again! Input (1 - " << floor((*itIngredent).getQuantity() / (*itDish).getQty()) << " ) (or Input `0` to exit): " << endl;
		cin >> qty;
		cin.ignore();
		if (qty == 0) {
			return;
		}
	}

	int addedQty = (*itDish).addIngredent(name, (*itIngredent).getMeasuredUnit(), qty);
	(*itDish).setIsActive(true);
	(*itIngredent).setQuantity((*itIngredent).getQuantity() - addedQty * (*itDish).getQty());
}
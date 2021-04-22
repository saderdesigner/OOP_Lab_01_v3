#include "OrderController.h"

vector<Meal> Store::vMeal;

void OrderManager() {
	bool stop = false;
	while (!stop)
	{
		cout << "________Order Manager" << endl;
		cout << "\t|____1. Create Order" << endl;
		cout << "\t|____2. Read Order" << endl;
		cout << "\t|____0. Back" << endl;

		int option;
		cin >> option;
		cin.ignore();
		switch (option)
		{
		// Create Order
		case 1:
		{
			CreateOrder();
			break;
		}
		case 2:
		{
			ReadOrder();
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

void CreateOrder()
{
	string waiterName, date, timeStart, timeEnd, address;
	int amountOfDinners, dishID;
	cout << "Input Waite's name: ";
	getline(cin, waiterName);
	cout << "Input Waite's address: ";
	getline(cin, address);
	cout << "Input date: ";
	getline(cin, date);
	cout << "Input starting time: ";
	getline(cin, timeStart);
	cout << "Input ending time: ";
	getline(cin, timeEnd);
	cout << "Input number of Dinners: ";
	cin >> amountOfDinners;
	cin.ignore();
	auto itTable = find_if(Store::vTable.begin(), Store::vTable.end(), [&amountOfDinners](Table& obj) {return (obj.getAmountOfDenners() <= amountOfDinners) && (obj.getIsReserved() == false); });
	if (itTable == Store::vTable.end()) {
		cout << "There is no Table Aviable please try again later! " << endl;
		return;
	}
	Table t = *itTable;
	Waiter w = Waiter(waiterName, address, 4000);
	int id = generateMealID();
	Meal meal = Meal(id, date, timeStart, timeEnd, w, t);


	

	bool loop = true;
	int numDish = 0;

	while (loop)
	{
		numDish++;
		viewListDish();
		cout << "Select Dishes[" << numDish << "]: ";
		cout << "Input Dish ID (or Input `0` to exit): ";
		cin >> dishID;
		cin.ignore();

		if (dishID == 0) {
			break;
		}

		auto itDish = find_if(Store::vDish.begin(), Store::vDish.end(), [&dishID](Dish& obj) {return obj.getId() == dishID; });
		while (itDish == Store::vDish.end())
		{
			cout << "Dish ID " << dishID << " not found! Please try again! (or Input `0` to exit)" << endl;
			cout << "Input Dish ID: ";
			cin >> dishID;
			cin.ignore();
			if (dishID == 0) {
				break;
			}

			itDish = find_if(Store::vDish.begin(), Store::vDish.end(), [&dishID](Dish& obj) {return obj.getId() == dishID; });
		}
		if (dishID == 0) {
			loop = false;
			break;
		}
		meal.addDish((*itDish));
	}
	Store::vMeal.push_back(meal);

	cout << "________Success________" << endl;
}

void viewListDish() {
	cout << "+---------------+------------------------------+" << endl;
	cout << "|" << std::setw(15) << left << "ID" << "|" << std::setw(30) << left << "DISH NAME" << "|" << endl;
	cout << "+---------------+------------------------------+" << endl;
	for (auto it = Store::vDish.begin(); it != Store::vDish.end(); it++) {
		if (!(*it).getIsActive()) {
			return;
		}

		cout << "|" << std::setw(15) << left << (*it).getId() << "|" << std::setw(30) << left << (*it).getName() << "|" << endl;
	}
	cout << "+---------------+------------------------------+" << endl;
}

int generateMealID() {
	int id = Store::vMeal.size();
	return 2000 + id + 1;
}

void ReadOrder() {
	cout << "+------+---------------+" << endl;
	cout << "|" << std::setw(6) << left << "ID" << "|"
				<< std::setw(15) << left << "WAITER" << "|"
				<< endl;
	for (auto i = Store::vMeal.begin(); i != Store::vMeal.end(); i++)
	{
		cout << "|" << std::setw(6) << left << (*i).getId() << "|"
			<< std::setw(15) << left << (*i).getWaiter().getName() << "|"
			<< endl;
	}
	cout << "+------+---------------+" << endl;
	cout << "Read Order" << endl;
	int id;
	cout << "Input Order ID: ";
	cin >> id;
	cin.ignore();

	auto it = find_if(Store::vMeal.begin(), Store::vMeal.end(), [&id](Meal& obj) {return obj.getId() == id; });

	if (it != Store::vMeal.end()) {
		printOrderAsTable((*it));
	}
	else {
		cout << "Meal ID " << id << " not found!" << endl;
	}
	return;
}

void printOrderAsTable(Meal& m) {
	cout << "+------+----------+----------+----------+----------+----------+--------------------+" << endl;
	cout << "|" << std::setw(6)		<< left << "ID"			<< "|" 
				<< std::setw(10)	<< left << "DATE"		<< "|" 
				<< std::setw(10)	<< left << "TIME START" << "|" 
				<< std::setw(10)	<< left << "TIME END"	<< "|"
				<< std::setw(10)	<< left << "WAITER"		<< "|"
				<< std::setw(10)	<< left << "TABLE"		<< "|"
				<< std::setw(20)	<< left << "DISH"		<< "|"
		<< endl;
	cout << "+------+----------+----------+----------+----------+----------+--------------------+" << endl;
	
	if (m.getListDish().empty()) {
		cout
			<< "|"
			<< std::setw(6) << left << "" << "|"
			<< std::setw(10) << left << "" << "|"
			<< std::setw(10) << left << "" << "|"
			<< std::setw(10) << left << "" << "|"
			<< std::setw(10) << left << "" << "|"
			<< std::setw(10) << left << "" << "|"
			<< std::setw(20) << left << "There is no dish!" << "|"
			<< endl;
	}
	else {
		cout
			<< "|"
			<< std::setw(6) << left << m.getId() << "|"
			<< std::setw(10) << left << m.getDate() << "|"
			<< std::setw(10) << left << m.getTimeStart() << "|"
			<< std::setw(10) << left << m.getTimeEnd() << "|"
			<< std::setw(10) << left << m.getWaiter().getName() << "|"
			<< std::setw(10) << left << m.getTable().getId() << "|"
			<< std::setw(20) << left << (*(m.getListDish().begin())).getName() << "|"
			<< endl;
		vector<Dish> d = m.getListDish();
		for (auto i = d.begin() + 1; i != d.end(); i++)
		{
			cout
				<< "|"
				<< std::setw(6) << left << "" << "|"
				<< std::setw(10) << left << "" << "|"
				<< std::setw(10) << left << "" << "|"
				<< std::setw(10) << left << "" << "|"
				<< std::setw(10) << left << "" << "|"
				<< std::setw(10) << left << "" << "|"
				<< std::setw(20) << left << (*i).getName() << "|"
				<< endl;
		}
	}
	cout << "+------+----------+----------+----------+----------+----------+--------------------+" << endl;
}


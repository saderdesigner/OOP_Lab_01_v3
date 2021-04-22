#include "TableController.h"

vector<Table> Store::vTable;

void TableManager() {
	bool stop = false;
	while (!stop)
	{
		cout << "________Table Manager" << endl;
		cout << "\t|____1. Create Table" << endl;
		cout << "\t|____2. Read Table" << endl;
		cout << "\t|____3. Update Table" << endl;
		cout << "\t|____4. Delete Table" << endl;
		cout << "\t|____5. Auto generate Tables" << endl;
		cout << "\t|____6. Show Reserved Tables" << endl;
		cout << "\t|____7. Show Aviable Tables" << endl;
		cout << "\t|____0. Back" << endl;

		int option;
		cin >> option;
		cin.ignore();
		switch (option)
		{
			// Create Table
		case 1:
		{
			CreateTable();
			break;
		}
		// Read Table
		case 2:
		{
			ReadTable();
			break;
		}
		// Update Table
		case 3:
		{
			printVector(Store::vTable);
			UpdateTable();
			break;
		}
		// Delete Table
		case 4:
		{
			printVector(Store::vTable);
			DeleteTable();
			break;
		}
		// Auto generate Tables
		case 5:
		{
			GenerateListTable();
			printVector(Store::vTable);
			break;
		}
		// Show Disabled Tables
		case 6:
		{
			cout << "________ Show Disabled Tables ________" << endl;
			printVector(Store::vTable, "reserved");
			break;
		}
		// Show Active Tables
		case 7:
		{
			cout << "________ Show Aviable Tables ________" << endl;
			printVector(Store::vTable, "aviable");
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

void CreateTable() {
	int id, amountOfDinners;

	cout << "Input ID: ";
	cin >> id;
	cin.ignore();

	cout << "Input Amount of Dinners:";
	cin >> amountOfDinners;


	Table i = Table(id, amountOfDinners);

	Store::vTable.push_back(i);

	cout << "\n________Created________\n" << endl;
}

void ReadTable()
{
	cout << "Read Table" << endl;
	int id;
	cout << "Input Table ID: ";
	cin >> id;
	cin.ignore();

	auto it = find_if(Store::vTable.begin(), Store::vTable.end(), [&id](Table& obj) {return obj.getId() == id; });

	if (it != Store::vTable.end()) {
		(*it).print("all");
	}
	else {
		cout << "Table ID " << id << " not found!" << endl;
	}
	return;
}

void UpdateTable() {
	cout << "\n________Updated________\n" << endl;
}

void DeleteTable() {
	cout << "\n________Deleted________\n" << endl;
}

void GenerateListTable()
{
	int lastID = 3000;
	if (!Store::vTable.empty()) {
		lastID = (*(Store::vTable.end() - 1)).getId();
	}
	Table w[10];
	int amountOfDinners, id;

	for (int i = 0; i < 10; i++) {

		id = lastID + i + 1;
		amountOfDinners = rand() % 20 + 1;

		w[i] = Table(id, amountOfDinners);

		Store::vTable.push_back(w[i]);
	}
}
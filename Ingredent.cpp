#include "Ingredent.h"

Ingredent::Ingredent()
{
	this->name = "";
	this->measuredUnit = "";
	this->qty = 0;
}

Ingredent::Ingredent(string name, string measuredUnit, int qty)
{
	this->name = name;
	this->measuredUnit = measuredUnit;
	this->qty = qty;
}

string Ingredent::getName()
{
	return this->name;
}

string Ingredent::getMeasuredUnit()
{
	return this->measuredUnit;
}

int Ingredent::getQuantity()
{
	return this->qty;
}

void Ingredent::setName(string name)
{
	this->name = name;
}

void Ingredent::setMeasuredUnit(string measuredUnit)
{
	this->measuredUnit = measuredUnit;
}

void Ingredent::setQuantity(int qty)
{
	this->qty = qty;
}

void Ingredent::print(string opt = "") {
	cout << std::setw(15) << left << "Ingredent[Name: " << std::setw(15) << right << this->name << std::setw(15) << left << ", Measure Unit: " << std::setw(15) << right << this->measuredUnit << std::setw(15) << left << ", Quantity: " << std::setw(15) << right << this->qty << "]" << endl;
}

void Ingredent::inputAndCreate()
{
	string name, measuredUnit;
	int qty;
	cout << "Input Ingredent Information:" << endl;
	cout << "Input name: " << endl;
	getline(cin, name);
	cout << "Input measuredUnit: " << endl;
	getline(cin, measuredUnit);
	cout << "Input qty: " << endl;
	cin >> qty;
	this->name = name;
	this->measuredUnit = measuredUnit;
	this->qty = qty;
}

void Ingredent::inputAndupdate()
{
	string name, measuredUnit, qty;
	cout << "Input Ingredent Information:" << endl;
	cout << "Input name: " << endl;
	getline(cin, name);
	cout << "Input measuredUnit: " << endl;
	getline(cin, measuredUnit);
	cout << "Input qty: " << endl;
	getline(cin, qty);
	if (name != "") {
		this->name = name;
	}
	if (measuredUnit != "") {
	this->measuredUnit = measuredUnit;
	}
	if (qty != "") {
	this->qty = stoi(qty);
	}
}

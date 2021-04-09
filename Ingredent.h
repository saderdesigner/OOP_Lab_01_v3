#pragma once
#include "main.h"

class Ingredent
{
private:
	string name;
	string measuredUnit;
	int qty;
public:
	Ingredent();
	Ingredent(string name, string measuredUnit, int qty);

	// get Function
	string getName();
	string getMeasuredUnit();
	int getQuantity();

	// set Funtion
	void setName(string name);
	void setMeasuredUnit(string measuredUnit);
	void setQuantity(int quantity);

	void print(string opt);

	friend ostream& operator << (ostream& os, const Ingredent& obj) {
		return (os << "Ingredent[Name: " << std::setw(10) << right << obj.name << ", Measure Unit: " << std::setw(10) << right << obj.measuredUnit << ", Quantity: " << std::setw(10) << right << obj.qty << "]" << endl);
	}

	//friend ostream& operator << (ostream& os, const Ingredent* obj) {
	//	return (os << "Ingredent[Name: " << std::setw(10) << right << obj->name << ", Measure Unit: " << std::setw(10) << right << obj->measuredUnit << ", Quantity: " << std::setw(10) << right << obj->qty << "]" << endl);
	//}

	void inputAndCreate();
	void inputAndupdate();
};




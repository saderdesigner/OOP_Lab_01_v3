#pragma once
#include "Main.h"

template <typename T>
void printVector(vector<T>& v, string opt = "") {
	string title = typeid(T).name();
	title.erase(0, 6);
	cout << endl;
	cout << "_____________________________________________________________________________________________" << endl;
	if (v.empty()) {
		cout << "List of " << title <<" is empty" << endl;
		return;
	}
	for (auto i = v.begin(); i != v.end(); i++) {
		//cout << *i;
		if (title != "Ingredent") {
			if (opt == "disable") {
				(*i).print("disable");
			}
			else if (opt == "active") {
				(*i).print("active");
			}
			else {
				(*i).print("all");
			}
		}
		else {
			(*i).print("all");
		}
		
	}
	cout << "_____________________________________________________________________________________________" << endl;
	cout << endl;
}

template <typename T>
void printDisabledVector(vector<T>& v) {
	if (typeid(T).name() != typeid(Dish).name())
	{
		return;
	}
	string title = typeid(T).name();
	title.erase(0, 6);
	cout << endl;
	if (v.empty()) {
		cout << "List of " << title << " is empty" << endl;
		return;
	}
	for (auto i = v.begin(); i != v.end(); i++) {
		//cout << *i;
		(*i).printDisabled();
	}
	cout << endl;
}
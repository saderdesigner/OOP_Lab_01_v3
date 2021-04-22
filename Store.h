#pragma once
#ifndef STORE_H
#define STORE_H
#include "Ingredent.h"
#include "Dish.h"
#include "Table.h"
#include "Meal.h"

class Store
{
public:
	static vector<Ingredent> vIngredent;
	static vector<Dish> vDish;
	static vector<Dish> vDisabledDish;
	static vector<Meal> vMeal;
	static vector<Table> vTable;
	Store() {};
};

#endif
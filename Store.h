#pragma once
#ifndef STORE_H
#define STORE_H
#include "Ingredent.h"
#include "Dish.h"

class Store
{
public:
	static vector<Ingredent> vIngredent;
	static vector<Dish> vDish;
	static vector<Dish> vDisabledDish;
	Store() {};
};

#endif
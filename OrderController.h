#pragma once
#include "Main.h"
#include "Store.h"
#include "Template.h"
#include "Waiter.h"

void OrderManager();
void CreateOrder();
void viewListDish();
void ReadOrder();
void UpdateOrder();
void DeleteOrder();
void AddDishToOrder();
int generateMealID();
void printOrderAsTable(Meal& m);
//void printOrderAsTable();
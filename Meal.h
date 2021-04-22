#pragma once
#include "Main.h"
#include "Waiter.h"
#include "Table.h"
#include "Dish.h"
class Meal
{
private:
	int id;
	string date;
	string timeStart;
	string timeEnd;
	Waiter waiter;
	Table table;
    vector<Dish> listDish;
public:
    Meal();
    Meal(
        int id,
        string date,
        string timeStart,
        string timeEnd,
        Waiter &waiter,
        Table &table
    );


    int getId() const;
    void setId(int it);

    string getDate() const;
    void setDate(string date);

    string getTimeStart() const;
    void setTimeStart(string timeStart);

    string getTimeEnd() const;
    void setTimeEnd(string timeEnd);

    Waiter getWaiter() const;
    void setWaiter(Waiter waiter);

    Table getTable() const;
    void setTable(Table table);

    bool hasIngredentName(const string& name);
    void addDish(Dish dish);
    vector<Dish> getListDish();
    void removeDish(const string& name);

    void print();

};


#pragma once
#include "Main.h"
#include "Ingredent.h"
class Dish
{
private:
    int id;
    string name;
    vector<Ingredent> listIngredent;
    int qty;
    bool isActive;
public:
    Dish();
    Dish(int id, string name, int qty);

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    int getQty() const;
    void setQty(int qty);

    friend ostream& operator << (ostream& os, const Dish& obj) {
        return (os << "Dish[ID: " << std::setw(10) << right << obj.id << ", Name: " << std::setw(10) << right << obj.name << ", Quantity: " << std::setw(10) << right << obj.qty << "]" << endl);
    }

    void print(string opt);
    void inputAndCreate();
    void inputAndupdate();

    /*This function return a vector of dish, which has ingredent `name`*/
    bool hasIngredentName(const string &name);

    /*  This function does:
    *   - Add new ingredent and return amount of ingredent added
    *   - Modify qty of existed ingredent and return new_qty - old_qty
    */
    int addIngredent(string name, string measuredUnit, int qty);

    bool getIsActive() const;
    void setIsActive(bool isActive);

};


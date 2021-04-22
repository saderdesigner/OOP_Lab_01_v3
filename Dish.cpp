#include "Dish.h"

Dish::Dish()
{
    this->id = 0;
    this->name = "";
    this->qty = 0;
    this->listIngredent.clear();
    this->isActive = false;
}

Dish::Dish(int id, string name, int qty)
{
    this->id = id;
    this->name = name;
    this->qty = qty;
    this->listIngredent.clear();
    this->isActive = false;
}

int Dish::getId() const
{
    return id;
}

void Dish::setId(int id)
{
    this->id = id;
}

string Dish::getName() const
{
    return name;
}

void Dish::setName(string name)
{
    this->name = name;
}

int Dish::getQty() const
{
    return qty;
}

void Dish::setQty(int qty)
{
    this->qty = qty;
}

void Dish::print(string opt = "")
{
    if (opt == "disable") {
        if (this->isActive == true) {
            return;
        }
    }
    if (opt == "active") {
        if (this->isActive == false) {
            return;
        }
    }
    cout << std::setw(15) << left << "Dish[ID: " << std::setw(15) << right << this->id << std::setw(15) << left << ", Name: " << std::setw(15) << right << this->name << std::setw(15) << left << ", Quantity: " << std::setw(15) << right << this->qty << "]" << endl;
    cout << "\t|________Ingredent List:" << endl;
    if (this->listIngredent.empty()) {
        cout << "\t\t|________No engredent in dish!" << endl;
    }
    else {
        for (auto it = this->listIngredent.begin(); it != this->listIngredent.end(); ++it) {
            cout << "\t\t|________";
            (*it).print("all");
        }
        cout << endl;
    }
}

void Dish::inputAndCreate()
{
    string name;
    int qty, id;
    cout << "Input Ingredent Information:" << endl;

    cout << "Input measuredUnit: " << endl;
    cin >> id;
    cin.ignore();

    cout << "Input name: " << endl;
    getline(cin, name);

    cout << "Input qty: " << endl;
    cin >> qty;
    cin.ignore();

    this->id = id;
    this->name = name;
    this->qty = qty;
}

void Dish::inputAndupdate()
{
    string name, qty, id;
    
    cout << "Input Dish Information:" << endl;

    cout << "Input ID: " << endl;
    cin >> id;
    cin.ignore();

    cout << "Input name: " << endl;
    getline(cin, name);

    cout << "Input qty: " << endl;
    cin >> qty;
    cin.ignore();

    if (id != "") {
        this->id = stoi(id);
    }
    if (name != "") {
        this->name = name;
    }
    if (qty != "") {
        this->qty = stoi(qty);
    }
}

bool Dish::hasIngredentName(const string &name)
{
    auto it = find_if(this->listIngredent.begin(), this->listIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });
    if (it != this->listIngredent.end()) {
        return true;
    }
    return false;
}

int Dish::addIngredent(string name, string measuredUnit, int qty)
{
    auto itIngredent = find_if(this->listIngredent.begin(), this->listIngredent.end(), [&name](Ingredent& obj) {return obj.getName() == name; });
    if (itIngredent == this->listIngredent.end()) {
        Ingredent i = Ingredent(name, measuredUnit, qty);
        this->listIngredent.push_back(i);
        cout << "________Success________" << endl;
        return qty;
    }
    else {
        int oldQty = (*itIngredent).getQuantity();
        cout << "Ingredent " << name << " is current in list. Update it's quantity from " << oldQty << " to " << qty << endl;
        (*itIngredent).setQuantity(qty);
        cout << "________Success________" << endl;
        return qty - oldQty;
    }
}


bool Dish::getIsActive() const
{
    return isActive;
}

void Dish::setIsActive(bool isActive)
{
    this->isActive = isActive;
}


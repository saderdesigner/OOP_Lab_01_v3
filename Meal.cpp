#include "Meal.h"

Meal::Meal()
{
    this->id = 0;
    this->date = "";
    this->timeStart = "";
    this->timeEnd = "";
}

Meal::Meal(int id, string date, string timeStart, string timeEnd, Waiter &waiter, Table &table)
{
    this->id = id;
    this->date = date;
    this->timeStart = timeStart;
    this->timeEnd = timeEnd;

    this->waiter = waiter;
    this->table = table;
}

int Meal::getId() const
{
    return this->id;
}

void Meal::setId(int id)
{
    this->id = id;
}

string Meal::getDate() const
{
    return date;
}

void Meal::setDate(string date)
{
    this->date = date;
}

string Meal::getTimeStart() const
{
    return timeStart;
}

void Meal::setTimeStart(string timeStart)
{
    this->timeStart = timeStart;
}

string Meal::getTimeEnd() const
{
    return timeEnd;
}

void Meal::setTimeEnd(string timeEnd)
{
    this->timeEnd = timeEnd;
}

Waiter Meal::getWaiter() const
{
    return waiter;
}

void Meal::setWaiter(Waiter waiter)
{
    this->waiter = waiter;
}

Table Meal::getTable() const
{
    return table;
}

void Meal::setTable(Table table)
{
    this->table = table;
}

bool Meal::hasIngredentName(const string& name)
{
    for (auto itDish = this->listDish.begin(); itDish != this->listDish.end(); itDish++) {
        if ((*itDish).hasIngredentName(name)) {
            return true;
        };
    }
    return false;
}

void Meal::addDish(Dish dish)
{
    this->listDish.push_back(dish);
}

vector<Dish> Meal::getListDish() {
    return this->listDish;
}

void Meal::removeDish(const string& name) 
{
    vector<Dish> newListDish;
    for (auto itDish = this->listDish.begin(); itDish != this->listDish.end(); itDish++) {
        if (!(*itDish).hasIngredentName(name)) {
            cout << (*itDish).getName() << endl;
            newListDish.push_back(*itDish);
        }

    }
    this->listDish.clear();
    for (auto itDish = newListDish.begin(); itDish != newListDish.end(); itDish++) {
        this->listDish.push_back(*itDish);
    }
    cout << "size: " << this->listDish.size() << endl;
    cout << "________Deleted________" << endl;
    //this->listDish.erase(remove_if(this->listDish.begin(), this->listDish.end(), [&name](Dish& ele)->bool {return ele.hasIngredentName(name); }), this->listDish.end());
}


void Meal::print()
{
    cout << std::setw(15) << left << "Meal[ID: " << std::setw(15) << right << this->id << std::setw(15) << left << ", Date: " << std::setw(15) << right << this->date << std::setw(15) << left << ", TimeStart: " << std::setw(15) << right << this->timeStart << ", TimeEnd: " << std::setw(15) << right << this->timeEnd << "]" << endl;
    cout << "\t|________";
    this->waiter.print();
    cout << "\t|________";
    this->table.print("all");
    
    if (this->listDish.empty()) {
        cout << "\t\t|________You haven't ordered yet!" << endl;
    }
    else {
        for (auto it = this->listDish.begin(); it != this->listDish.end(); ++it) {
            cout << "\t\t|________";
            (*it).print("all");
        }
        cout << endl;
    }
}


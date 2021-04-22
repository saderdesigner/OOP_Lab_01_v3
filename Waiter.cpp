#include "Waiter.h"

Waiter::Waiter()
{
    this->name = "";
    this->address = "";
    this->id = 0;
}

Waiter::Waiter(string name, string address, int id)
{
    this->name = name;
    this->address = address;
    this->id = id;
}

int Waiter::getId() const
{
    return id;
}

void Waiter::setId(int id)
{
    this->id = id;
}

void Waiter::print()
{
    cout << "Waiter[Name: " << std::setw(20) << right << this->name << ", Address: " << std::setw(20) << right << this->address << ", ID: " << std::setw(10) << right << this->id << "]" << endl;
}


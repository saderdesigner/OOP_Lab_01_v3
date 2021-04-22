#include "Person.h"

Person::Person()
{
    this->name = "";
    this->address = "";
}

Person::Person(string name, string adress)
{
    this->name = name;
    this->address = address;
}

string Person::getName() const
{
    return name;
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getAddress() const
{
    return address;
}

void Person::setAddress(string address)
{
    this->address = address;
}


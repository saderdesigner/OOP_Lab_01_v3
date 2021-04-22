#pragma once
#include "main.h"
class Person
{
protected:
    string name;
    string address;
public:
    Person();
    Person(string name, string adress);

    string getName() const;
    void setName(string name);

    string getAddress() const;
    void setAddress(string address);

};
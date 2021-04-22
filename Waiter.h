#pragma once
#include "Person.h"
class Waiter :
    public Person
{
private:
    int id;
public:
    Waiter();
    Waiter(string name, string address, int id);
    int getId() const;
    void setId(int id);
    friend ostream& operator << (ostream& os, const Waiter& obj) {
        return (os << "Waiter[Name: " << std::setw(20) << right << obj.name << ", Address: " << std::setw(20) << right << obj.address << ", ID: " << std::setw(10) << right << obj.id << "]" << endl);
    }

    void print();
};


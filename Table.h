#pragma once
#include "main.h"

class Table
{
private:
    int id;
    int amountOfDenners;
    bool isReserved;
public:
    Table();
    Table(int id, int amountOfDenners);

    int getId() const;
    void setId(int id);

    int getAmountOfDenners() const;
    void setAmountOfDenners(int amountOfDenners);

    bool getIsReserved() const;
    void setIsReserved(bool isReserved);

    void print(string opt);

    friend ostream& operator << (ostream& os, const Table& obj) {
        return (os << "Table[id: " << std::setw(20) << right << obj.id << ", amountOfDenners: " << std::setw(20) << right << obj.amountOfDenners << endl);
    }
};


#include "Table.h"

Table::Table()
{
    this->id = 0;
    this->amountOfDenners = 0;
    this->isReserved = false;
}

Table::Table(int id, int amountOfDenners)
{
    this->id = id;
    this->amountOfDenners = amountOfDenners;
    this->isReserved = false;
}

int Table::getId() const
{
    return id;
}

void Table::setId(int id)
{
    this->id = id;
}

int Table::getAmountOfDenners() const
{
    return amountOfDenners;
}

void Table::setAmountOfDenners(int amountOfDenners)
{
    this->amountOfDenners = amountOfDenners;
}


bool Table::getIsReserved() const
{
    return isReserved;
}

void Table::setIsReserved(bool isReserved)
{
    this->isReserved = isReserved;
}

void Table::print(string opt = "")
{
    if (opt == "reserved") {
        if (this->isReserved == true) {
            return;
        }
    }
    if (opt == "aviable") {
        if (this->isReserved == false) {
            return;
        }
    }
    cout << "_____________________________________________________________________________________________" << endl;
    cout << std::setw(15) << left << "Table[ID: " << std::setw(15) << right << this->id << std::setw(15) << left << ", Amount Of Dinners: " << std::setw(15) << right << this->amountOfDenners << "]" << endl;
}


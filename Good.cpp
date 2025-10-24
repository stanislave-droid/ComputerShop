#include "Good.h"
#include <iostream>
#include "ArrayOfProducts.h"

bool Good::SearchInGood(std::string property)
{
    if(property == name){ return true; }
    else {
        if (property == producer) { return true; }
        else {
            if (property == std::to_string(frequency)) { return true; }
            else {
                if (property == size) { return true; }
                else { return false; }
            }
        }
    }
}

void Good::ChangeStatsInProduct()
{
    std::cout << "\nProduct " << id << std::endl;
    std::cout << "Write product name: ";
    std::cin >> this->name;
    std::cout << "Write product producer: ";
    std::cin >> this->producer;
    std::cout << "Write product frequency: ";
    std::cin >> this->frequency;
    std::cout << "Write product size: ";
    std::cin >> this->size;
}


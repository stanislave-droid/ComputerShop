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
    while (true) {
        std::cout << "\nProduct " << id << std::endl;
        std::cout << "Write product name: ";
        std::cin >> name;
        std::cout << "Write product producer: ";
        std::cin >> producer;
        std::cout << "Write product frequency: ";
        std::cin >> frequency;
        std::cout << "Write product size: ";
        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "\n\nWrong answer 0_0, try again\n";
        }
        else { break; }
    }
}


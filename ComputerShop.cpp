#include <iostream>
#include <string>
#include "Tables.h"
#include "Good.h"

int option();

int Good::count = 0;

int main()
{
    std::cout << "Hello, i am Stinislave!\n";
    std::cout << "This is my project to practice 1.\n";
    std::cout << "I hope you like it, i tried my best!\n";

    Tables t;

    while (true) {
        switch (option()) {
        case 1:
            t.WriteToConsole();
            break;
        case 2:
            t.AddGoodsToTable();
            break;
        case 3:
            t.Search();
            break;
        }
    }

}
int option() {
    std::string which = "";

    while (true) {
        std::cout << "\n1. Open shop 2. Add new goods 3. Search by name" << std::endl;
        std::cout << "Select an option available above: ";

        std::cin >> which;
        if (which == "1" || which == "2" || which == "3") { break; }
        else { std::cerr << "\nWrong answer, try again\n";  continue; }
    }

    return std::stoi(which);
}

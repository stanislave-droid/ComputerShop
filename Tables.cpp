#include "Tables.h"
#include "TextTable.h"
#include "ArrayOfProducts.h"
#include "Good.h"

TextTable t('-', '|', '+');
TextTable* ptrT = &t;
ArrayOfProducts products;

void Tables::CreateTable()
{
    ptrT->add("Id");
    ptrT->add("Name");
    ptrT->add("Producer");
    ptrT->add("Frequency(hz)");
    ptrT->add("Size");
    ptrT->endOfRow();
    ptrT->setAlignment(2, TextTable::Alignment::LEFT);
}

void Tables::WriteToConsole()
{
    std::cout << *ptrT;
}

void Tables::AddGoodsToTable()
{
    int count = 0;
    
    while (true) {
        std::cout << "\nHow many products do you want to add?" << std::endl;
        std::cout << ": ";
        std::cin >> count;
        if (count != 0) { break; }
        else { std::cerr << "\nWrong answer 0_0\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
    }
    
    products.AddProducts(count);
    for (int i = products.Array.size() - count; i < products.Array.size(); i++) {
        ptrT->add(std::to_string(products.Array.at(i).id));
        ptrT->add(products.Array.at(i).name);
        ptrT->add(products.Array.at(i).producer);
        ptrT->add(std::to_string(products.Array.at(i).frequency));
        ptrT->add(products.Array.at(i).size);
        ptrT->endOfRow();
    }

    //if (products.Array.empty() {
    //    //products.CreateArray(rows);
    //    products.AddProducts();
    //    for (int i = 0; i < rows; i++) {
    //        ptrT->add(std::to_string(products.Array[i].id));
    //        ptrT->add(products.Array[i].name);
    //        ptrT->add(products.Array[i].producer);
    //        ptrT->add(std::to_string(products.Array[i].frequency));
    //        ptrT->add(products.Array[i].size);
    //        ptrT->endOfRow();
    //    }
    //}
    //else {
    //    /*products.CopyAddAndReCreate(rows);
    //    products.AddProducts();
    //    for (int i = 0; i < rows; i++) {
    //        ptrT->add(std::to_string(products.Array[i]->id));
    //        ptrT->add(products.Array[i]->name);
    //        ptrT->add(products.Array[i]->producer);
    //        ptrT->add(std::to_string(products.Array[i]->frequency));
    //        ptrT->add(products.Array[i]->size);
    //        ptrT->endOfRow();
    //    }*/
    //    std::cerr << "\nSorry, but i didn`t add it yet\n" << std::endl; // it didn`t want to work (ver2 - but now it works, grateful for vector)
    //}
}

void Tables::Search()
{
    std::string searchingProperty = "";
    std::vector<int> idOfProductWeSearch;
    TextTable TemporaryTable('-', '|', '+');
    bool sometingIsHere = false;

    TemporaryTable.add("Id");
    TemporaryTable.add("Name");
    TemporaryTable.add("Producer");
    TemporaryTable.add("Frequency(hz)");
    TemporaryTable.add("Size");
    TemporaryTable.endOfRow();
    TemporaryTable.setAlignment(2, TextTable::Alignment::LEFT);

    if (products.Array.empty()) {
        std::cerr << "\nPls, add products before search, because here is nothing 0_0\n";
        return;
    }
    else {
        std::cout << "\nWrite a name or other property to find your product: ";
        std::cin >> searchingProperty;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "\n\nWrong answer 0_0, error in input _0_0_ \n";
        }

        for (int i = 0; i < products.Array.size(); i++) {
            if (products.Array[i].SearchInGood(searchingProperty)) { idOfProductWeSearch.push_back(i); sometingIsHere = true; }
            else { continue; }
        }
        if (sometingIsHere) {

            for (int i = 0; i < idOfProductWeSearch.size(); i++) {
                TemporaryTable.add(std::to_string(products.Array.at(idOfProductWeSearch[i]).id));
                TemporaryTable.add(products.Array.at(idOfProductWeSearch[i]).name);
                TemporaryTable.add(products.Array.at(idOfProductWeSearch[i]).producer);
                TemporaryTable.add(std::to_string(products.Array.at(idOfProductWeSearch[i]).frequency));
                TemporaryTable.add(products.Array.at(idOfProductWeSearch[i]).size);
                TemporaryTable.endOfRow();
            }

            std::cout << TemporaryTable;

        }
        else {
            std::cerr << "\nHere is no product with your property 0_0" << std::endl;
        }
    }
}


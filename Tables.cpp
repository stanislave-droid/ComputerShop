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
    if (products.Array == nullptr) {
        std::cout << "\nHow many products do you want to add?" << std::endl;
        std::cout << ": ";
        std::cin >> rows;
    }

    if (products.Array == nullptr) {
        products.CreateArray(rows);
        products.AddProducts();
        for (int i = 0; i < rows; i++) {
            ptrT->add(std::to_string(products.Array[i]->id));
            ptrT->add(products.Array[i]->name);
            ptrT->add(products.Array[i]->producer);
            ptrT->add(std::to_string(products.Array[i]->frequency));
            ptrT->add(products.Array[i]->size);
            ptrT->endOfRow();
        }
    }
    else {
        /*products.CopyAddAndReCreate(rows);
        products.AddProducts();
        for (int i = 0; i < rows; i++) {
            ptrT->add(std::to_string(products.Array[i]->id));
            ptrT->add(products.Array[i]->name);
            ptrT->add(products.Array[i]->producer);
            ptrT->add(std::to_string(products.Array[i]->frequency));
            ptrT->add(products.Array[i]->size);
            ptrT->endOfRow();
        }*/
        std::cerr << "\nSorry, but i didn`t add it yet\n" << std::endl; // it didn`t want to work
    }
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

    if (products.Array == nullptr) {
        std::cerr << "\nPls, add products before search, because here is nothing 0_0\n";
        return;
    }
    else {
        std::cout << "\nWrite a name or other property to find your product: ";
        std::cin >> searchingProperty;

        for (int i = 0; i < rows; i++) {
            if (products.Array[i]->SearchInGood(searchingProperty)) { idOfProductWeSearch.push_back(i); sometingIsHere = true; }
            else { continue; }
        }
        if (sometingIsHere) {

            for (int i = 0; i < idOfProductWeSearch.size(); i++) {
                TemporaryTable.add(std::to_string(products.Array[idOfProductWeSearch[i]]->id));
                TemporaryTable.add(products.Array[idOfProductWeSearch[i]]->name);
                TemporaryTable.add(products.Array[idOfProductWeSearch[i]]->producer);
                TemporaryTable.add(std::to_string(products.Array[idOfProductWeSearch[i]]->frequency));
                TemporaryTable.add(products.Array[idOfProductWeSearch[i]]->size);
                TemporaryTable.endOfRow();
            }

            std::cout << TemporaryTable;

        }
        else {
            std::cerr << "Here is no product with your property 0_0" << std::endl;
        }
    }
}


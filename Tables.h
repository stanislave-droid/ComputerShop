#pragma once
#include <string>
#include "ArrayOfProducts.h"

class Tables
{
	int rows = 1;
	void CreateTable();
	void AddProducts();
public:
	
	Tables() {
		CreateTable();
	}

	void WriteToConsole();
	void AddGoodsToTable();
	void Search();
};


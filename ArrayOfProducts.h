#pragma once
#include "Good.h"
#include <vector>

class ArrayOfProducts
{
	int count;

public:
	//Good** Array;

	/*~ArrayOfProducts(){
		for (int i = 0; i < this->count; i++) {
			if (Array[i] != nullptr) { delete Array[i]; }
		}
		delete[] Array;
	}*/
	
	std::vector<Good> Array;
	
	//void CreateArray(int count);
	void AddProducts(int count);
	void CreateProducts();
	//void CopyAddAndReCreate(int count);
};


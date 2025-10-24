#pragma once
#include "Good.h"

class ArrayOfProducts
{
	int count;

public:
	Good** Array;

	~ArrayOfProducts(){
		for (int i = 0; i < this->count; i++) {
			if (Array[i] != nullptr) { delete Array[i]; }
		}
		delete[] Array;
	}
	
	void CreateArray(int count);
	void AddProducts();
	void CopyAddAndReCreate(int count);
};


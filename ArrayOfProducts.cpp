#include "ArrayOfProducts.h"
#include <iostream>
#include <string>

//void ArrayOfProducts::CreateArray(int count)
//{
//	/*this->count = count;
//	Array = new Good * [this->count];
//	for (int i = 0; i < this->count; i++) {
//		Array[i] = new Good();
//	}*/
//}

void ArrayOfProducts::AddProducts(int count)
{
	/*for (int i = 0; i < count; i++) {
		if (Array[i]->name == "" && Array[i]->frequency == -1) {
			Array[i]->ChangeStatsInProduct();
		}
	}*/
	
	Array.reserve(count);

	for (int i = 0; i < count; i++) {
		CreateProducts();
	}
	for (int i = (Array.size() - count); i < Array.size(); i++) {
		Array.at(i).ChangeStatsInProduct();
	}
}

void ArrayOfProducts::CreateProducts()
{
	Good Template;
	Array.push_back(Template);
	Template.count++;
}

//void ArrayOfProducts::CopyAddAndReCreate(int count)
//{
//	Good** TemporaryArray;
//	TemporaryArray = new Good * [count+this->count];
//
//	for (int i = 0; i < this->count; i++) {
//		TemporaryArray[i] = Array[i];
//	}
//	
//	this->count += count;
//	count = 0;
//	Array = TemporaryArray;
//
//	for (int i = this->count - 1; i < (this->count + count); i++) {
//		Array[i] = new Good();
//	}
//}


#pragma once
#include <string>

class Good
{
public:
	static int count;
	int id;
	std::string name;
	std::string producer;
	int frequency;
	std::string size;

	Good() {
		id = ++count;
		name = "";
		producer = "";
		frequency = -1;
		size = "";
	}
	
	bool SearchInGood(std::string property);
	void ChangeStatsInProduct();
};


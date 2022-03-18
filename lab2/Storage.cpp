#include "Storage.h"
#include <iostream>

using namespace std;

Storage::Storage()
{
}

Storage::Storage(string name_value, double price_value, int quant_value, int num_value)
{
	name = name_value;
	price = price_value;
	quant = quant_value;
	num = num_value;
	count++;
}

Storage::~Storage()
{
}

int Storage::count = 0;
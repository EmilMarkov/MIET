#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Storage
{
private:
	string name;
	double price;
public:
	int quant;
	int num;
	static int count;

	Storage();
	Storage(string name_value, double price_value, int quant_value, int num_value);
	~Storage();

	// Get functions
	string getName()
	{
		return name;
	}
	double getPrice()
	{
		return price;
	}
	int getQuant()
	{
		return quant;
	}
	int getNum()
	{
		return num;
	}

	// Set functions
	void setName(string name_value)
	{
		name = name_value;
	}
	void setPrice(double price_value)
	{
		price = price_value;
	}
	void setQuant(int quant_value)
	{
		quant = quant_value;
	}
	void setNum(int num_value)
	{
		num = num_value;
	}

	// Functions
	void search_by_name(Storage*& database, int N)
	{
		string name_value;

		cout << endl << "Enter name for search in database: "; cin >> name_value; cout << endl;

		for (int i = 0; i < N; i++)
		{
			if (database[i].getName() == name_value)
			{
				cout << "Name: " << database[i].getName() << endl;
				cout << "Price: " << database[i].getPrice() << endl;
				cout << "Quant: " << database[i].getQuant() << endl;
				cout << "Num: " << database[i].getNum() << endl;
				cout << "######################################" << endl;
			}
			cout << endl;
		}
		system("pause");
	}

	void filter_by_section(Storage*& database, int N)
	{
		int section_value;

		cout << endl << "Enter section number for filter database: "; cin >> section_value; cout << endl;

		for (int i = 0; i < N; i++)
		{
			if (database[i].getNum() == section_value)
			{
				cout << "Name: " << database[i].getName() << endl;
				cout << "Price: " << database[i].getPrice() << endl;
				cout << "Quant: " << database[i].getQuant() << endl;
				cout << "Num: " << database[i].getNum() << endl;
				cout << "######################################" << endl;
			}
			cout << endl;
		}
		system("pause");
	}

	friend void sort_by_quant(Storage*& database);
};
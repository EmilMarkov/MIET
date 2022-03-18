#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include "Storage.h"

using namespace std;

string path = "data.txt";

int N = 0;

int string_to_int(string str)
{
    int result;
    istringstream iss(str, istringstream::in);
    iss >> result;
    return result;
}

double string_to_double(string str)
{
    double result;
    istringstream iss(str, istringstream::in);
    iss >> result;
    return result;
}

void save(Storage*& database)
{
    fstream datainput;
    datainput.open(path, ios::out);
    for (int i = 0; i < N; i++)
    {
        datainput << database[i].getName() << endl << database[i].getPrice() << endl << database[i].getQuant() << endl << database[i].getNum() << endl << database[i].count << endl;
    }
    datainput.close();
}

void load(Storage*& database)
{
    fstream datainput;
    datainput.open(path, ios::in);
    int i = 0;
    for (int j = 0; j < N * 5;)
    {
        for (i = 0; i < 5; i++)
        {
            switch (i)
            {
                case 0:
                {
                    string line;
                    getline(datainput, line);
                    database[j / 5].setName(line);
                    break;
                }
                case 1:
                {
                    string line;
                    getline(datainput, line);
                    database[j / 5].setPrice(string_to_double(line));
                    break;
                }
                case 2:
                {
                    string line;
                    getline(datainput, line);
                    database[j / 5].setQuant(string_to_int(line));
                    break;
                }
                case 3:
                {
                    string line;
                    getline(datainput, line);
                    database[j / 5].setNum(string_to_int(line));
                    break;
                }
                case 4:
                {
                    string line;
                    getline(datainput, line);
                    database[j / 5].count = string_to_int(line);
                    break;
                }
            }
        }
        j = j + 5;
    }
    datainput.close();
}

void Value_N(int& N) {
    fstream read;
    read.open(path, ios::in);
    int count = 0;
    string per;
    while (read.peek() != EOF) {
        getline(read, per);
        ++count;
        if (count % 5 == 0)
        {
            ++N;
        }
    }
}

void add(Storage*& database, int& N)
{
    string string_buffer; double double_buffer; int int_buffer;
    cout << "Please input product name: "; cin >> string_buffer;
    database[N].setName(string_buffer);
    cout << "Please input product price: "; cin >> double_buffer;
    database[N].setPrice(double_buffer);
    cout << "Please input quant of products: "; cin >> int_buffer;
    database[N].setQuant(int_buffer);
    cout << "Please input section number: "; cin >> int_buffer;
    database[N].setNum(int_buffer);
    database[N].count++;
    N++;
    cout << "Product was added." << endl << endl;
    system("pause");
}

void print(Storage*& database)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Name: " << database[i].getName() << endl;
        cout << "Price: " << database[i].getPrice() << endl;
        cout << "Quant: " << database[i].getQuant() << endl;
        cout << "Num: " << database[i].getNum() << endl;
        cout << "######################################" << endl;
    }
    cout << endl;
    system("pause");
}

bool comp(int a, int b)
{
    if (a > b)
        return a < b;
    else
        return a > b;
}

void sort_by_quant(Storage*& database)
{
    map<int, Storage> arr;
    vector<int> quant_;

    for (int i = 0; i < N; i++)
    {
        quant_.push_back(database[i].getQuant());
        arr[quant_[i]] = database[i];
    }

    Storage* result = new Storage[N];

    int j = N;

    for (auto& i : arr)
    {
        result[j-1] = i.second;
        j--;
    }

    print(result);
}

void menu(Storage*& database)
{
    cout << "=============================================" << endl;
    cout << "Current functions:" << endl;
    cout << "1) Add product to DB." << endl;
    cout << "2) Print all products from DB." << endl;
    cout << "3) Search product by name." << endl;
    cout << "4) Filter products by section number." << endl;
    cout << "5) Sort products by count decrease." << endl;
    cout << "6) Exit program." << endl;
    cout << "=============================================" << endl << endl;


    int choice = 0;

    while (choice != 6)
    {
        cout << "Type function number: "; cin >> choice; cout << endl;

        if (choice == 1)
        {
            add(database, N);
        }
        else if (choice == 2)
        {
            print(database);
        }
        else if (choice == 3)
        {
            database->search_by_name(database, N);
        }
        else if (choice == 4)
        {
            database->filter_by_section(database, N);
        }
        else if (choice == 5)
        {
            sort_by_quant(database);
        }
        else if (choice == 6)
        {
            save(database);
            cout << "Program was exit..." << endl;
            exit(0);
        }
        else {
            bool next = false;

            while (!next) {
                if (choice < 1 or choice > 6)
                {
                    cout << "Function number was not find. Try again..." << endl;
                    cin >> choice; cout << endl;
                }
            }
        }
    }
}

int main()
{
    Storage* database = new Storage[100];

    Value_N(N);
    load(database);

    menu(database);

    return 0;
}

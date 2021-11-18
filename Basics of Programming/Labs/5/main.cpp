#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

//функция для инициализации массива слов из строк
vector<string> init_words(vector<string> v) {
	string str;
	getline(cin, str);
	istringstream ist(str);
	for (string word; ist >> word; v.push_back(word));

	return v;
}

//функция для инициализации массива длин слов из строк
vector<int> init_len_words(vector<string> v) {
	vector <int> mass;
	for (int i = 0; i < v.size(); i++) {
		string word = v[i];
		mass.push_back(word.size());
	}
	return mass;
}

//вывод массива слов
void print_words(vector<string> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

//вывод массива длин слов
void print_len_words(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	//объявление массивов слов из строк
	vector <string> str1;
	vector <string> str2;

	//объявление массивов длин слов из строк 
	vector <int> str1_len;
	vector <int> str2_len;

	//инициализация массивов слов
	str1 = init_words(str1);
	str1 = init_words(str2);

	//инициализация массивов длин слов
	str1_len = init_len_words(str1);
	str2_len = init_len_words(str2);

	print_words(str1);
	print_words(str2);

	return 0;
}
//Задание 1
// 
//#include <iostream>
//#include <locale.h>
//
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//
//	const int N = 5;
//	int a[N];
//	int max1 = -2147483n147;
//	int max2 = -2147483n147;
//
//	cout << "Введите элементы массива:" << endl;
//	for (int i = 0; i < N; i++) 
//	{
//		cout << "a[" << i << "] = ";
//		cin >> a[i];
//
//		if (a[i] % 2 == 0)
//		{
//			if (a[i] > max1)
//			{
//				max1 = a[i];
//			}
//		}
//		if (a[i] > max2)
//		{
//			max2 = a[i];
//		}
//
//	}
//	cout << "Максимальное значение для чётных чисел: "<< max1 <<",максимальное значение среди всех чисел : " << max2;
//}

#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	setlocale(LC_ALL, "Rus");

	const int n1 = 6;
	const int n2 = 9;
	int a[n1][n2];
	int m[(n2-1)/2];
	int sum = 0;
	int ind = 0;

	for (int i = 0; i < (n2 - 1) / 2; i++)
		m[i] = 0;

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = n1/2; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			sum += a[i][j];
		}
	}

	cout << "Сумма элементов заштрихованной области: " << sum << endl;

	for (int j = 0; j < n2; j++)
	{
		if ((j + 1) % 2 == 0)
		{
			for (int i = 0; i < n1; i++)
			{
				if (a[i][j] == 0)
				{
					m[ind]++;
				}
			}
			ind++;
		}
	}

	for (int i = 0; i < (n2-1)/2; i++)
	{
		cout << m[i] << " ";
	}
}
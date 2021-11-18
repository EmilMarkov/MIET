//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
//double find_min(double* M, const int N)   //функция для поиска индекса минимального значения массива
//{
//	double min = M[0];   //минимальный элемент
//	int index_min = 0;   //индекс минимального элемента
//	for (int i = 0; i < N; ++i)
//	{
//		if (M[i] < min)
//		{
//			index_min = i;
//		}
//	}
//	return index_min;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	srand(time(0));
//
//	const int N1 = 8;   //кол-во элементов 1-го массива
//	const int N2 = 8;   //кол-во элементов 2-го массива
//	double A[N1];   //массив №1
//	double B[N2];   //массив №2
//	double index_min1;   //индекс минимального элемента 1-го массива
//	double index_min2;   //индекс минимального элемента 2-го массива
//	double sum1 = 0;   //сумма элементов правой части 1-го массива
//	double sum2 = 0;   //сумма элементов правой части 2-го массива
//
//	for (int i = 0; i < N1; ++i)   //заполняем массив №1
//	{
//		A[i] = rand() % 100;
//	}
//	for (int i = 0; i < N2; ++i)   //заполняем массив №2
//	{
//		B[i] = rand() % 100;
//	}
//
//	index_min1 = find_min(A, N1);
//	index_min2 = find_min(B, N2);
//
//	for (int i = N1 - 1; i < index_min1; --i)
//	{
//		sum1 += A[i];
//	}
//	for (int i = N2 - 1; i < index_min2; --i)
//	{
//		sum2 += B[i];
//	}
//	
//	if (sum1 / (N1 - index_min1) > sum2 / (N2 - index_min2))
//	{
//		cout << "Среднее арифметическое правой части 1-го массива больше.";
//	}
//	else if (sum1 / (N1 - index_min1) < sum2 / (N2 - index_min2))
//	{
//		cout << "Среднее арифметическое правой части 2-го массива больше.";
//	}
//	else
//	{
//		cout << "Среднее арифметическое правой части массивов равны.";
//	}
//}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sum_elem(int num, int N, int *M) //Функция для суммирования элементов в заданной строке заштрихованной(по заданию) области.
{
	int result = 0; //Результат работы функции
	if (N % 2 == 0) //Условие для чётной матрицы
	{
		if (num >= 1 and num <= N / 2) //Условие для строки в промежутке от 1 до N/2
		{
			for (int j = N - 1; j >= N - num; --j)
				result += M[j];
		}
		else if (num >= (N + 2) / 2 and num <= N) //Условие для строки в промежутке от (N+2)/2 до N
		{
			for (int j = N - 1; j >= num - 1; --j)
				result += M[j];
		}	
	}
	else //Условие для нечётной матрицы
	{
		if (num >= 1 and num <= (N - 1) / 2) //Условие для строки в промежутке от 1 до (N-1)/2
		{
			for (int j = N - 1; j >= N - num; --j)
				result += M[j];
		}
		else if (num >= (N + 1) / 2 and num <= N) //Условие для строки в промежутке от (N+1)/2 до NS
		{
			for (int j = N - 1; j >= num - 1; --j)
				result += M[j];
		}
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	const int N = 10; //Размер матрицы N*N
	int M[N][N]; //Матрица
	int num; //Номер строки
	
	for (int i = 0; i < N; i++) //Заполнение массива
	{
		for (int j = 0; j < N; j++)
		{
			M[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < N; i++) //Вывод массива
	{
		for (int j = 0; j < N; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}

	cin >> num; //Ввод номера строки пользователем

	cout << "Сумма элементов в выбранной строке: " << sum_elem(num, N, M[num - 1]) << endl; //Вывод результата
	cout << "Сумма элементов в остальных строках: " << endl;

	for (int i = 0; i < N; ++i) {
		cout << "	" << i + 1 << ")" << " " << sum_elem(i + 1, N, M[i]) << endl;
	}
}
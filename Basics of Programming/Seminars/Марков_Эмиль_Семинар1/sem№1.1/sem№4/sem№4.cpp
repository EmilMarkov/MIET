#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));   //данная функция необходима для правильной работы rand()
	setlocale(LC_ALL, "Rus");   //локализация

	const int N = 8;   //количество элементов в массиве
	int M[N];   
	int index_min;   //индекс минимального числа массива

	for (int i = 0; i < N; i++)   //заполнение массива рандомными значениями
	{
		M[i] = rand() % 100;
	}

	int min = M[0];   //переменная для минимального числа массива

	for (int i = 0; i < N; i++)   //поиск минимального числа
	{
		if (M[i] < min)
		{
			min = M[i];
		}
	}

	printf("Массив до: \n");   //вывод массива до изменений
	for (int i = 0; i < N; i++)
	{
		printf("%d ", M[i]);
	}
	printf("\n");

	for (int i = 0; i < N; i++)   //замена минимального числа его индексом
	{
		if (M[i] == min)
		{
			M[i] = i;
			index_min = i;
		}
	}

	printf("Массив после: \n");   //вывод измененного массива
	for (int i = 0; i < N; i++)
	{
		printf("%d ", M[i]);
	}
	printf("\n");
	printf("Минимальное число - %d, оно имеет индекс %d.", min, index_min);
}
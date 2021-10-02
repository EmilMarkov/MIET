#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");   //локализация

	int x, y;   //координаты точки

	printf("Введите координаты точки(x и y, через пробел): ");
	scanf_s("%d %d", &x, &y);

	if (x > 0 and y > 0)
	{
		printf("Точка находится в 1 четверти.");
	}
	else if (x < 0 and y > 0)
	{
		printf("Точка находится в 2 четверти.");
	}
	else if (x < 0 and y < 0)
	{
		printf("Точка находится в 3 четверти.");
	}
	else if (x > 0 and y < 0)
	{
		printf("Точка находится в 4 четверти.");
	}
}
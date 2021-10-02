//Задание 1
//
//#include <stdio.h>
//#include <locale.h>
//
//int main()
//{
//    setlocale(LC_ALL, "Rus");
//    int d;
//
//    printf("Введите число: ");
//    scanf_s("%d", &d);
//    
//    switch (d % 10)
//    {
//    case 1:
//        printf("%d копейка", d);
//        break;
//    case 2:
//        printf("%d копейки", d);
//        break;
//    case 3:
//        printf("%d копейки", d);
//        break;
//    case 4:
//        printf("%d копейки", d);
//        break;
//    case 5:
//        printf("%d копеек", d);
//        break;
//    case 6:
//        printf("%d копеек", d);
//        break;
//    case 7:
//        printf("%d копеек", d);
//        break;
//    case 8:
//        printf("%d копеек", d);
//        break;
//    case 9:
//        printf("%d копеек", d);
//        break;
//    case 0:
//        printf("%d копеек", d);
//        break;
//    }
//}

//задание 2
//
//#include <stdio.h>
//#include <locale.h>
//
//int main() 
//{
//    setlocale(lc_all, "rus");
//    int n;
//
//    printf("введите день недели: \n");
//    scanf_s("%d", &n);
//
//    if (n >= 1 and n < 6) {
//        printf("рабочей день");
//    }
//    else if (n == 6) {
//        printf("суббота");
//    }
//    else if (n == 7) {
//        printf("воскресенье");
//    }
//    else {
//        printf("ошибка. неверный номер дня недели!");
//    }
//}

//Задание 3
//
//#include <stdio.h>
//#include <locale.h>
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int a, b, n = 0;
//	printf("Введите(через пробел) начало и конец отрезка: ");
//	scanf_s("%d %d", &a, &b);
//
//	if (a % 5 == 0) {
//		while (a <= b)
//		{
//			n += a;
//			a += 5;
//		}
//		printf("Сумма чисел кратных 5 равна: %d", n);
//	}
//	else {
//		while (a % 5 != 0) {
//			a++;
//		}
//		while (a <= b)
//		{
//			n += a;
//			a += 5;
//		}
//		printf("Сумма чисел кратных 5 равна: %d", n);
//	}
//}
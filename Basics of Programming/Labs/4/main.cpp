#define Q4 //смена упражнений(например, в данном случае Q4 - это значит, что выбранно 4 упражение
#ifdef Q1

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define N1 10
#define N2 10
#define r1 10

void mass_init(int* m, int r) { // m - одномерный массив, n - размер массива, r - число для указания диапазона чисел
	int* pointer_c; // текущий указатель
	for (pointer_c = m; pointer_c < (m + N1); ++pointer_c)
	{
		*pointer_c = rand() % (r * 3 + 1) - r;
	}
}

void mass_print(int* m) {
	int* pointer_c; // текущий указатель
	for (pointer_c = m; pointer_c < (m + N1); ++pointer_c)
	{
		cout << setw(3) << *pointer_c << " ";
	}
	cout << endl;
}

int* mass_find_otr(int* m) {
	int* pointer_c; // текущий указатель
	for (pointer_c = m; pointer_c < (m + N1); ++pointer_c) {
		if (*pointer_c < 0) {
			break;
		}
	}
	return pointer_c;
}

double mass_right_avg(int* m, int* pointer_otr, double* pointer_avg) {
	int* pointer_c;
	int count = 0;
	for (pointer_c = pointer_otr; pointer_c < (m + N1); ++pointer_c, ++count) {
		*pointer_avg += *pointer_c;
	}
	*pointer_avg /= count;
	return *pointer_avg;
}

int main() {
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int A[N1], B[N2];
	mass_init(A, r1);
	mass_init(B, r1);
	cout << "Массив А: ";
	mass_print(A);
	cout << "Массив В: ";
	mass_print(B);

	int* pointer_otr_A = mass_find_otr(A);;
	int* pointer_otr_B = mass_find_otr(B);;

	double avg_A = 0;
	double avg_B = 0;

	double* pointer_avg_A = &avg_A;
	double* pointer_avg_B = &avg_B;

	mass_right_avg(A, pointer_otr_A, pointer_avg_A);
	mass_right_avg(B, pointer_otr_B, pointer_avg_B);

	cout << "Среднее арифметическое правой части массива " << "A - " << avg_A << endl;
	cout << "Среднее арифметическое правой части массива " << "B - " << avg_B;

	return 0;
}

#endif

#ifdef Q2
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define N1 10
#define N2 12
#define r1 10

void mass_init(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N1); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + N2); ++pointer_c_m) {
			*pointer_c_m = rand() % (r1 * 3 + 1) - r1;
		}
	}
}

void mass_print(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N1); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + N2); ++pointer_c_m) {
			cout << setw(3) << *pointer_c_m << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int sum_1ch(int** m, int* sum) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < m + N1 / 2; ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n + N2 / 2; pointer_c_m < *pointer_c_n + N2; ++pointer_c_m) {
			*sum += *pointer_c_m;
		}
	}
	return *sum;
}

int sum_3ch(int** m, int* sum) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m + N1 / 2; pointer_c_n < m + N1; ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < *pointer_c_n + N2 / 2; ++pointer_c_m) {
			*sum += *pointer_c_m;
		}
	}
	return *sum;
}

int main() {
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int** A = (int**)calloc(N1, sizeof(int*));
	for (int i = 0; i < N1; i++) A[i] = (int*)calloc(N2, sizeof(int));
	int B[N2];
	int sum1 = 0; // сумма элементов 1 четверти
	int sum3 = 0; // сумма элементов 3 четверти
	double sum = 0; //сумма двух четвертей

	mass_init(A);
	mass_print(A);

	sum = sum_1ch(A, &sum1) + sum_3ch(A, &sum3);

	cout << "Среднее арифметическое заштрихованной области: " << sum / (N1 * N2 / 2) << endl;
}
#endif

#ifdef Q3

#define N 10 //строки
#define M 12 //столбцы
#define r 10

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void mass_init(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + M); ++pointer_c_m) {
			*pointer_c_m = rand() % (r * 3 + 1) - r;
		}
	}
}

void mass_print(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + M); ++pointer_c_m) {
			cout << setw(3) << *pointer_c_m << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void avg_arr(int** m, double* avg_arr) {
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			*avg_arr += m[i][j];
		}
		cout << setw(3) << *avg_arr/N << " ";
		*avg_arr = 0;
	}
}

int main() {
	srand(time(0));
	int** A = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) A[i] = (int*)calloc(M, sizeof(int));

	double B[M];
	for (int i = 0; i < M; i++) B[i] = 0;

	mass_init(A);
	mass_print(A);
	avg_arr(A, B);
}

#endif

#ifdef Q4

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define N 4 //строки
#define M 4 //столбцы
#define r1 10

void mass_init(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + M); ++pointer_c_m) {
			*pointer_c_m = rand() % (r1 * 3 + 1) - r1;
		}
	}
}

void mass_print(int** m) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m; pointer_c_n < (m + N); ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < (*pointer_c_n + M); ++pointer_c_m) {
			cout << setw(3) << *pointer_c_m << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int sum_1ch(int** m, double* sum) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	if (N % 2 == 0) {
		for (pointer_c_n = m; pointer_c_n < m + N / 2; ++pointer_c_n) {
			for (pointer_c_m = *pointer_c_n + M / 2; pointer_c_m < *pointer_c_n + M; ++pointer_c_m) {
				*sum += *pointer_c_m;
			}
		}
	}
	else
	{
		for (pointer_c_n = m; pointer_c_n <= m + N / 2; ++pointer_c_n) {
			for (pointer_c_m = *pointer_c_n + M / 2; pointer_c_m < *pointer_c_n + M; ++pointer_c_m) {
				*sum += *pointer_c_m;
			}
		}
	}
	return *sum;
}

int sum_3ch(int** m, double* sum) {
	int** pointer_c_n; // текущий указатель строки
	int* pointer_c_m; // текущий указатель столбца
	for (pointer_c_n = m + N / 2; pointer_c_n < m + N; ++pointer_c_n) {
		for (pointer_c_m = *pointer_c_n; pointer_c_m < *pointer_c_n + M / 2; ++pointer_c_m) {
			*sum += *pointer_c_m;
		}
	}
	return *sum;
}

void avg_arr(double sum_1ch, double sum_3ch) {
	cout << "Среднее арифметическое 1 четверти: " << sum_1ch / (round((double)N / 2) * round((double)M / 2)) << endl;
	cout << "Среднее арифметическое 3 четверти: " << sum_3ch / (round((double)N / 2) * round((double)M / 2)) << endl;
}

int main() {
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int** A = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) A[i] = (int*)calloc(M, sizeof(int));
	int B[M];
	double sum1 = 0; // сумма элементов 1 четверти
	double sum3 = 0; // сумма элементов 3 четверти

	mass_init(A);
	mass_print(A);

	sum1 = sum_1ch(A, &sum1);
	sum3 = sum_3ch(A, &sum3);

	avg_arr(sum1, sum3);

}
#endif
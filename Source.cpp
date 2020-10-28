#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <chrono>

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int matrix(void)
{
	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	time_t start, end; // объявляем переменные для определения времени выполнения
	int n, m, elem_c;
	printf("Программа для перемножения матриц\nВведи размерность матрицы через пробел: ");
	scanf_s("%d %d", &n, &m);
	int i = 0, j = 0, r;
	int** A;
	int** B;
	int** C;
	A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	B = new int* [n];
	for (int i = 0; i < n; i++) {
		B[i] = new int[m];
	}
	C = new int* [n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[m];
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < n)
	{
		while (j < m)
		{
			A[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < m)
	{
		while (j < m)
		{
			B[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	printf("\nИдет перемножение матриц...\n");
		time(&start);
		Timer t;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				elem_c = 0;
				for (r = 0; r < n; r++)
				{
					elem_c = elem_c + A[i][r] * B[r][j];
					C[i][j] = elem_c;

				}
			}
		}
		time(&end);
		int seconds = difftime(end, start);

		printf("\nЗатраченное время на просчет составляет: %f сек (библиотека chrono)", t.elapsed());
		printf("\nЗатраченное время на просчет составляет: %d сек (библиотека time.h)\n", seconds);
		printf("\nНажмите ENTER для выхода в главное меню... \n");
		_getch();
		return 0;
}

void qs(int* items, int left, int right) 
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

void ss(int n, int mass[])
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}

}

int rand1()
{
	int N;
	printf("Введи количество элементов в массиве: ");
	scanf_s("%d", &N);
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		mass[i] = rand() % N + 1;
	Timer t;
	ss(N, mass);
	printf("\nЗатраченное время на сортировку: %f сек (Шелла) ", t.elapsed());
	Timer t1;
	qs(mass, 0, N - 1);
	printf("\nЗатраченное время на сортировку: %f сек (Быстрая) ", t1.elapsed());
	_getch();
	return 0;
}

int up()
{
	int a, N;
	printf("Введи количество элементов в массиве: ");
	scanf_s("%d", &N);
	a = 0;
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		mass[i] = a++;
	Timer t;
	ss(N, mass);
	printf("\nЗатраченное время на сортировку: %f сек (Шелла) ", t.elapsed());
	Timer t1;
	qs(mass, 0, N - 1);
	printf("\nЗатраченное время на сортировку: %f сек (Быстрая) ", t1.elapsed());
	_getch();
	return 0;
}

int down()
{
	int a, N;
	printf("Введи количество элементов в массиве: ");
	scanf_s("%d", &N);
	a = N;
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		mass[i] = a--;
	Timer t;
	ss(N, mass);
	printf("\nЗатраченное время на сортировку: %f сек (Шелла) ", t.elapsed());
	Timer t1;
	qs(mass, 0, N - 1);
	printf("\nЗатраченное время на сортировку: %f сек (Быстрая) ", t1.elapsed());
	_getch();
	return 0;
}

int pyramid()
{
	int a, N, M;
	printf("Введи количество элементов в массиве: ");
	scanf_s("%d", &N);
	a = 0;
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	M = N / 2;
	for (int i = 0; i < M; i++) {
		mass[i] = a++;
	}
	for (int i = M; i < N; i++) {
		mass[i] = a--;
	}
	/*
	for (int i = 0; i < N; i++) {
		printf("%d ", mass[i]);
	}
	*/
	Timer t;
	ss(N, mass);
	printf("\nЗатраченное время на сортировку: %f сек (Шелла) ", t.elapsed());
	Timer t1;
	qs(mass, 0, N - 1);
	printf("\nЗатраченное время на сортировку: %f сек (Быстрая) ", t1.elapsed());
	_getch();
	return 0;
}

int Menu(void)
{
	system("CLS");
	int c = 0;
	setlocale(LC_ALL, "Rus");
	while (c < '0' || c > '5')
	{
		printf(
			"::=================================::\n"
			"|| 1 : Перемножение матриц         ||\n"
			"|| 2 : Рандомный массив            ||\n"
			"|| 3 : Возрастающий массив         ||\n"
			"|| 4 : Убывающий массив            ||\n"
			"|| 5 : Пирамидальный массив        ||\n"
			"::=================================::\n"
			"> ");
		c = _getch();
		system("cls");
	}
	return c;
}

void main(void)
{
	int Select;
	while ((Select = Menu()) != '0' && Select != 27)
		switch (Select)
		{
		case '1':
			matrix();
			break;

		case '2':
			rand1();
			break;

		case '3':
			up();
			break;

		case '4':
			down();
			break;

		case '5':
			pyramid();
			break;
		}
}
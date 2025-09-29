#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение 
 * @return 
 */
double getY(const double x);


int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	printf("Введите начальное значение: ");
	double start = getValue();
	printf("Введите конечное значение: ");
	double end = getValue();
	printf("Введите шаг: ");
	double step = getValue();
	checkStep(step);
	for (double x = start; x < end + DBL_EPSILON; x = x + step)
	{
		if (defineOOF(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		}
		else
		{
			printf("x = %.2lf, не принадлежит ООФ\n", x);
		}
	}
	return 0;
}

double getValue()
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		abort();
	}
	return value;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Ошибка, шаг должен быть положительным\n");
		abort();
	}
}

bool defineOOF(const double x)
{
	return x > 0;
}

double getY(const double x)
{
	return log(x) + x;
}

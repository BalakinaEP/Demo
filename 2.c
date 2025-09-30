#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
 * @brief рассчитывает факториал числа
 * @param n - заданное число
 * @return рассчитанное значение
 */
int factorial(const int n);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите n = ");
    int n = getValue();
    printf("n! = %d",factorial(n));

    return 0;
}

int factorial(const int n)
{
    if (n<=1) return 1;
    return n * factorial(n-1);
}

int getValue()
{
	int value = 0;
	if (!scanf("%d", &value))
	{
		printf("Error\n");
		abort();
	}
	return value;
}

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
    int result = 1;
    for (int i = 1; i<=n; i++)
    {
        result*=i;
    }
    return result;
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

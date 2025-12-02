#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите x:");
    double x = getDouble();
    printf("Введите e:");
    double e = getDouble();
    checkPositive(e);
    printf("sin(x) = %.20lf\n", sin(x));
    printf("Сумма последовательности с точностью "
            "%.10lf равна %.20lf\n",
                    e,getSumE(e,x));

    return 0;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}


double getRecurent(const int i,const double x)
{
    return -1.0*x*x/(2*i+2)/(2*i+3);
}

void checkPositive(const double value)
{
    if (!value > 0)
    {
        printf("Error\n");
        exit(1);
    }
}

double getSumE(const double e, const double x)
{
    double current = x;
    double result = 0;
    const double y = sin(x);
    
    for (int i = 0; fabs(y - result) > e; i++)
    {
        result += current;
        current*=getRecurent(i,x);
    }
    return result;
}

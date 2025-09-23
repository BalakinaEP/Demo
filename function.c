#include <stdio.h>

/**
 * @brief - Расчет функции y по формуле
 * @param x - значение переменной х
 * @return - рассчитанное значение
 */
double getY(const double x);

/**
 * @brief - Точка входа в программу
 * @return - вызвращает 0, если программа выполнена корректно
 */
int main()
{
    double x = 0;
    scanf("%lf",&x);
    printf("y = %.2lf",getY(x));
    return 0;
}

double getY(const double x)
{
    if (x < 0.3)
    {
        return 3-x;
    }
    else if (x>0.3)
    {
        return 1.0/x;
    }
    else 
    {
        return 0;
    }
}

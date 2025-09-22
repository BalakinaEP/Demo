#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 3.1;
    const double y = 2.5;
    const double z = -1.7;
    printf("A = %lf", getA(x, y, z));
    printf("B = %lf", getB(x, y, z));
    return 0;
}

double getB(const double x, const double y, const double z)
{
    return exp(getA(x, y, z));
}

double getA(const double x, const double y, const double z)
{
    return M_PI + x + y - z;
}

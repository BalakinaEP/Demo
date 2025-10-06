#include <stdio.h>

/**
 * @brief рассчитывает периметр квадрата
 * @param side сторона квадрата
 * @return возвращает рассчитанный Периметр
 */
double getPerimetr(const double side);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double side = 0;
    scanf("%lf",&side);
    printf("Сторона равна %.2lf\n", side);
    printf("Периметр равен %.2lf",getPerimetr(side));

    return 0;
}

double getPerimetr(const double side)
{
    return side * 4;
}

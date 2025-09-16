#include <stdio.h>
#include <math.h>

/**
 * @brief рассчитывает гипотенузу прямоуголього треугольника
 * @param fistSide первая сторона прямоуголього треугольника
 * @param secondSide вторая сторона прямоуголього треугольника
 * @return возвращает рассчитанное значение
 */
double getHypotenuse(const double fistSide, 
                        const double secondSide);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double fistSide;
    double secondSide;
    printf("Введите первую сторону треугольника: ");
    scanf("%lf",&fistSide);
    printf("Введите вторую сторону треугольника: ");
    scanf("%lf",&secondSide);
    printf("Стороны равны %.2lf и %.2lf\n", 
                fistSide, secondSide);
    printf("Гипотенуза равна %.2lf",
            getHypotenuse(fistSide, secondSide));

    return 0;
}

double getHypotenuse(const double fistSide, 
                        const double secondSide)
{
    return sqrtf(pow(fistSide,2) + pow(secondSide,2));
}

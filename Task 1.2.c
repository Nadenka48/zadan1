#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief рассчитывает площадь прямоуголього треугольника
 * @param fistSide первая сторона прямоуголього треугольника
 * @param secondSide вторая сторона прямоуголього треугольника
 * @return возвращает рассчитанное значение
 */
double Ploshad(const double firstSide, const double secondSide);

/**
 * @brief рассчитывает периметр прямоуголього треугольника
 * @param fistSide первая сторона прямоуголього треугольника
 * @param secondSide вторая сторона прямоуголього треугольника
 * @return возвращает рассчитанное значение
 */
double Perimetr(const double firstSide, const double secondSide);



/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double firstSide=0;
    double secondSide=0;
    printf("Введите первую сторону треугольника: ");
    scanf("%lf", &firstSide);
    printf("Введите вторую сторону треугольника: ");
    scanf("%lf", &secondSide);
    printf("Площадь равна %.2lf\n", Ploshad(firstSide, secondSide));
    
    printf("Периметр равен %.2lf\n", Perimetr(firstSide, secondSide));
    return 0;
}

double Ploshad(const double firstSide, const double secondSide)
{
    return (firstSide * secondSide) / 2;
}

double Perimetr(const double firstSide, const double secondSide)
{
    return (firstSide + secondSide + (sqrtf(pow(firstSide, 2) + pow(secondSide, 2))));

}

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
*@brief считывает значение, введенное с клавиатуры с проверкой ввода
* @return считанное значение
*/
double getValue();

/**
*@brief проверяет, что минимальное значение меньше максимального
* @param start наименьшее значение промежутка
* @param end наибольшее значение промежутка
*/
void checkMinMax(const double start, const double end);

/**
*@brief проверяет, что переменная положительная
* @param step значение проверяемой переменной
*/
void checkStep(const double step);

/**
*@brief рассчитывает значение функции y по заданной формуле
* @param x значение
* @return расчитанное значение
*/
double getY(const double x);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    printf("Введите начальное значение: ");
    double start = getValue();
    printf("Введите конечное значение: ");
    double end = getValue();
    checkMinMax(start, end);
    printf("Введите шаг: ");
    double step = getValue();
    checkStep(step);
    for (double x = start; x < end + step; x += step)
    {
        printf("x = %.2lf, y = %.4lf\n", x, getY(x));
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

void checkMinMax(const double start, const double end) {
    if (start > end || fabs(start - end) <= DBL_EPSILON) {
        printf("end must be more than start.");
        abort();
    }
}

double getY(const double x)
{
    return cos(x) - exp(-pow(x, 2) / 2) + x - 1;
}

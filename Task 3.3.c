#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMM(const double min, const double max);

/**
 * @brief Проверяет, что шаг функции положительный
 * @param step значение шага функции
 */
void checkStep(const double step);

/**
 * @brief Проверяет, что число положительное
 * @param value проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет значение заданной функции
 * @param x значение параментра x
 * @return рассчитанное значение
 */
double func(const double x);

/**
 * @brief Вычисляет коэффициент рекуррентного выражения
 * @param n текущий индекс
 * @param x значение параментра x
 * @return рассчитанное значение
 */
double getRecurrent(const int n, const double x);

/**
 * @brief Считает сумму членов ряда с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Введите начальное значение: ");
    double min = getDouble();
    printf("Введите конечное значение: ");
    double max = getDouble();
    checkMM(min, max);
    printf("Введите шаг: ");
    double step = getDouble();
    checkStep(step);
    printf("Введите точность e: ");
    double e = getDouble();
    checkPositive(e);
    for (double x = min; x <= max + DBL_EPSILON; x += step)
    {
        printf("x = %.4lf, y(x) = %.6lf, S(x) = %.6lf\n",
            x, func(x), getSumE(e, x));
    }
    return 0;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка, введено неверное значение!\n");
        exit(1);
    }
    return value;
}

void checkMM(const double min, const double max)
{
    if (min - DBL_EPSILON >= max)
    {
        printf("Ошибка, минимальное значение должно быть меньше максимального!\n");
        exit(1);
    }
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка, шаг должен быть положительным!\n");
        exit(1);
    }
}

void checkPositive(const double value)
{
    if (value <= DBL_EPSILON)
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}

double func(const double x)
{
    return x * (3.0 - x) / pow(1.0 - x, 3.0);
}

double getRecurrent(const int n, const double x)
{
    return ((n + 1.0) * (n + 3.0) * x) / (n * (n + 2.0));
}

double getSumE(const double e, const double x)
{
    double current = 3.0 * x;
    double sum = current;

    for (int n = 1; fabs(current) > e; n++)
    {
        current *= getRecurrent(n, x);
        sum += current;
    }

    return sum;
}
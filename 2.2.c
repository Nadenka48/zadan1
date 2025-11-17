#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>

/**
 * @brief Функция расчитывающая значение y при x > a
 * @param x Входная величина
 * @return Значение функции
 */
double get_y_1(double x);

/**
 * @brief Функция расчитывающая значение y при x <= a
 * @param x Входная величина
 * @return Значение функции
 */
double get_y_2(double x);

/**
 * @brief Функция принимающая и проверяющая значение на ввод
 * @return Значение
 */
double get_value();

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
    double x;
    puts("Enter x: ");
    x = get_value();
    double result = 0;
    const int a = 5;
    if (x > a)
    {
        result = get_y_1(x);
    }
    else if (x <= a)
    {
        result = get_y_2(x);
    }
    else
    {
        errno = EIO;
        perror("Wrong value");
        return 1;
    }
    printf("%lf", "Результат: ", result);
    return 0;
}
double get_y_1(double x)
{
    double y = tan(x) + (M_PI / 3.0);
    return y;
}
double get_y_2(double x)
{
    double y = sin(x) * a;
    return y;
}
double get_value()
{
    double a;
    int res = scanf_s("%lf", &a);
    if (res != 1)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return a;
}
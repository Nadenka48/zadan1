#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Введите параметр A: ");
    double a = getValue();
    printf("Введите параметр B: ");
    double b = getValue();
    printf("Введите параметр C: ");
    double c = getValue();
    if (a < b && b < c)
    {
        double A = 2 * a;
        double B = 2 * b;
        double C = 2 * c;
        printf("A=%lf B=%lf C=%lf", A, B, C);
    }
    else {
        double A = fabs(a);
        double B = fabs(b);
        double C = fabs(c);
        printf("A=%lf B=%lf C=%lf", A, B, C);
    }
    return 0;
}
double getValue()
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        printf("Error\n");
        abort();
    }
    return value;
}
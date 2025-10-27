#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief считает энегрию,которую надо затратить
 * @param с удельная теплоёмкость (постоянное значение)
 * @param λ удельная теплота (постоянное значение)
 * @param m масса
 * @param delT изменение температуры
*/
int getQ(const int m);

/** @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корренктно
 */

int main() 
{
    setlocale(LC_ALL, "Russian");
    double m = 0;
    printf("Введите значение массы в килограммах: ");
    m = getValue();
    checkValue(m);
    printf("Энергия, которую надо затратить: %d\n", getQ(m));
    return 0;
}

int getQ(const int m)
{
    int c = 2100;
    int delT = 10;
    int λ = 334000;
    return (c * m * delT) + λ*m;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}

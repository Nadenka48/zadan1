#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считаем сумму
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанную сумму
 */
double getsym(const double a, const double b);

/**
 * @brief считаем разность
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанную разность
 */
double getraz(const double a, const double b);

/**
 * @brief считаем среднее арифметическое значение
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанное среднее арифметическое значение
 */
double getsr(const double a, const double b);
/**
* @brief sym сумма
* @brief raz разность
* @brief sr средннее арифметическое
*/
enum{sym, raz, sr};

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double value();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Введите значение a:");
    double a = value();
    printf("Введите значение b:");
    double b = value();
    printf("Выберите, что хотите посчитать: %d - сумма, %d - разность, %d - среднее арифметичекое\n", sym, raz, sr);
    int choice = (int) value();
    switch (choice)
    {
    case sym:
        printf("сумма равна %.2lf\n", getsym(a, b));
        break;
    case raz:
        printf("разность равна %.2lf\n", getraz(a, b));
        break;
    case sr:
        printf("среднее арифметическое равно %.2lf\n", getsr\(a, b));
        break;
    default:
        printf("Вы ввели неверное значение!");
        abort();
    }
    return 0;
}


double value()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return value;
}

double getsym(const double a, const double b)
{
    return a + b;
}

double getraz(const double a, const double b)
{
    return a - b;
}

double getsr(const double a, const double b)
{
    return (a + b) / 2;
}

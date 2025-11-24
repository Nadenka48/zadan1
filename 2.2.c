#pragma warning(disable:4996)
#define _USE_MATH_DEFINES
#include <stdio.h>

/**
 *@brief считывает значение, введенное с клавиатуры с проверкой ввода
 *@return считанное значение
 */
double getValue();

/**
 *@brief Функция, которая расчитывается по заданной формуле
 *@param x - введённое значение x, a = константа равная 2
 *@return рассчитанное значение функции
 */
double getF(const double x, const double a);

/**
 *@brief Точка входа в программу
 *@return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const double a = 2;
	printf("Введите значение х: ");
	double x = getValue();
	printf("Функция у = %.5lf", getF(x, a));
	return 0;
}

double getValue()
{
	double value = 0;
	if (!scanf("%lf", &value))
	{
		printf("Error");
		abort();
	}
	return value;
}

double getF(const double x, const double a)
{
	if (x > a)
	{
		return tan(x) + M_PI / 3;
	}
	return sin(x) * a;
}


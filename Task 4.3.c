#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

	/**
	* @brief Считывает число с проверкой ввода и проверяет на условие
	* @return Число
	*/
	const size_t getValidForSize();
	/**
	* @brief Считывает число с проверкой ввода
	* @return Число
	*/
	int getValidForDigit();
	/**
	* @brief Проверяет промежуток на корректность
	* @param min_ - начало промежутка
	* @param max_ - конец промежутка
	*/
	void check_min_max(const int min_, const int max_);

	/**
	* @brief Проверяет лежит ли число в промежутке [min;max]
	* @param value - число
	* @param min - нижняя граница значения элемента
	* @param min - верхняя граница значения элемента
	*/
	void checkMinMaxForDigit(const int value, const int min, const int max);

	/**
	* @brief Выделяет память под массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @return Массив
	*/
	int** getMakeArrays(const size_t rows, const size_t columns);

	/**
	* @brief Создаёт новый массив, идентинчый элементами прообразу
	* @param arr - массив прообраз
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @return Новый массив
	*/
	int** getCopyArray(int** arr, const size_t rows, const size_t columns);

	/**
	* @brief Проверяет, корректно ли выделилась память под массив
	* @param arr - массив
	* @param rows - количество строк массива
	*/
	void checkArraysFromMemory(int** arr, const size_t columns);

	/**
	* @brief Выводит на экран полученный массив
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	*/
	void printArrays(int** arr, const size_t rows, const size_t columns);

	/**
	* @brief Заполняет массив элементами, который вводит пользователь
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @param min - нижняя граница значения элемента
	* @param min - верхняя граница значения элемента
	*/
	void getManual(int** arr, const size_t rows, const size_t size_m, const int min, const int max);

	/**
	* @brief Заполняет массив случайными элементами
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @param min - нижняя граница значения элемента
	* @param min - верхняя граница значения элемента
	*/
	void getRandom(int** arr, const size_t rows, const size_t columns, const int min, const int max);

	/**
	* @brief Очищает выделенную память под массив
	* @param arr - массив
	* @param rows - количество строк массива
	*/
	void freeArraysMemory(int** arr, const size_t rows);

	/**
	* @brief Выводит новый массив согласно заданию №1
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	*/
	void defTaskOne(int** arr, const size_t rows, const size_t columns);

	/**
	* @brief Выводит новый массив согласно заданию №2
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	*/
	void defTaskTwo(int** arr, const size_t rows, const size_t columns);

	/**
	* @param MANUAL - выбор ручного создания массива
	* @param RANDOM - выбор автоматического создания массива
	* @param TASK_ONE - выбор первого задания
	* @param TASK_TWO - выбор второго задания
	*/
	enum { MANUAL = 1, RANDOM, TASK_ONE = 1, TASK_TWO };

	/**
	* @brief Находит минимальный элемент массива
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @return Минимальный элемент массива
	*/
	const int getMin(int** arr, const size_t rows, const size_t columns);

	/**
	* @brief Находит есть ли в строке минимальный элемент
	* @param arr - массив
	* @param rows - количество строк массива
	* @param columns - количесвто столбцов массива
	* @param min - минимальный элемент
	* @return количество строк, содержащих минимальный элемент
	*/
	const int count_getMin(int** arr, const size_t rows, const size_t columns, const int min);

	/**
	* @brief Выводит ошибку в соответсвующий поток и завершает программу
	* @param text - текст ошибки
	*/
	void ERROR(const char* text);

	/**
	* @brief Точка входа в программу
	* @return Возвращает 0, если программа была выполнена корректно, иначе 1
	*/
	int main(void)
	{
		setlocale(LC_ALL, "Russian");
		printf("Введите количество строк массива: ");
		size_t rows = getValidForSize();
		printf("Введите количество столбцов массива: ");
		size_t columns = getValidForSize();

		printf("\nВведите минимальное значение элемента массива: ");
		const int min = getValidForDigit();
		printf("Введите максимальное значение элемента массива: ");
		const int max = getValidForDigit();
		check_min_max(min, max);

		printf("Элементы массива будут задаваться в промежутке [%d;%d]\n", min, max);

		int** mainArray = getMakeArrays(rows, columns);
		checkArraysFromMemory(mainArray, rows);

		printf("\nВыберите метод заполнение массива:\n%d - Ручное заполнение массива\n%d - Автоматическое заполнение массива\n", MANUAL, RANDOM);
		int firstChoise = getValidForDigit();
		switch (firstChoise)
		{
		case MANUAL:
			getManual(mainArray, rows, columns, min, max);
			break;
		case RANDOM:
			getRandom(mainArray, rows, columns, min, max);
			break;
		default:
			freeArraysMemory(mainArray, rows);
			ERROR("Ошибка выбора");
		}
		int** newArray = getCopyArray(mainArray, rows, columns);
		checkArraysFromMemory(newArray, rows);
		printArrays(newArray, rows, columns);
		printf("\nВыберите выполняемую операцию с массивом:\n%d - Заменить максимальный элемент каждой строки номером столбца, в которой он находится\n%d - Вставить после всех строк, содержащих минимальный элемент массива, строку 2, 4, 6,...\n", TASK_ONE, TASK_TWO);
		int secondChoise = getValidForDigit();
		switch (secondChoise)
		{
		case TASK_ONE:
			defTaskOne(newArray, rows, columns);
			break;
		case TASK_TWO:
			defTaskTwo(newArray, rows, columns);
			break;
		default:
			freeArraysMemory(newArray, rows);
			freeArraysMemory(mainArray, rows);
			ERROR("Ошибка выбора");
		}
		freeArraysMemory(newArray, rows);
		freeArraysMemory(mainArray, rows);
		return 0;
	}

	const size_t getValidForSize()
	{
		long int value = 0;
		if (!scanf_s("%ld", &value))
		{
			ERROR("Ошибка ввода размерности массива");
		}
		if (value < 1)
		{
			ERROR("Ошибка ввода размерности массива");
		}
		size_t output = (size_t)value;
		return output;
	}

	int getValidForDigit()
	{
		int value = 0;
		if (!scanf_s("%d", &value))
		{
			ERROR("Ошибка ввода");
		}
		return value;
	}

	void check_min_max(const int min_, const int max_)
	{
		if (min_ >= max_)
		{
			ERROR("Ошибка ввода промежутка");
		}
	}

	void checkMinMaxForDigit(const int value, const int min, const int max)
	{
		if (value > max || value < min)
		{
			ERROR("Ошибка ввода, число вне промежутка");
		}
	}

	int** getMakeArrays(const size_t rows, const size_t columns)
	{
		int** arr = (int**)calloc(rows, sizeof(int*));

		if (arr == NULL)
		{
			ERROR("Ошибка выделения памяти под массив");
		}

		for (size_t i = 0; i < rows; i++)
		{
			arr[i] = (int*)calloc(columns, sizeof(int));
		}
		return arr;
	}

	void checkArraysFromMemory(int** arr, const size_t rows)
	{
		if (arr == NULL)
		{
			ERROR("Ошибка выделения памяти под массив");
		}
		else
		{
			for (size_t i = 0; i < rows; i++)
			{
				if (arr[i] == NULL)
				{
					ERROR("Ошибка выделения памяти под массив");
				}
			}
		}
	}

	void printArrays(int** arr, const size_t rows, const size_t columns)
	{
		checkArraysFromMemory(arr, rows);
		printf("\nПолученный массив:\n");
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				printf("%5d", arr[i][j]);
			}
			printf("\n");
		}
	}

	void getManual(int** arr, const size_t rows, const size_t columns, const int min, const int max)
	{
		checkArraysFromMemory(arr, rows);
		printf("\nВведите %zu элементов массива:\n", rows * columns);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				int num = getValidForDigit();
				checkMinMaxForDigit(num, min, max);
				printf("A[%zu][%zu] = %d\n", i, j, num);
				arr[i][j] = num;
			}
		}
	}

	void getRandom(int** arr, const size_t rows, const size_t columns, const int min, const int max)
	{
		checkArraysFromMemory(arr, rows);
		srand(time(NULL));
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				arr[i][j] = rand() % (max - min + 1) + min;
			}
		}
	}

	void freeArraysMemory(int** arr, const size_t size_n)
	{
		checkArraysFromMemory(arr, size_n);
		for (size_t i = 0; i < size_n; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}

	int** getCopyArray(int** arr, const size_t rows, const size_t columns)
	{
		checkArraysFromMemory(arr, rows);
		int** array = getMakeArrays(rows, columns);
		checkArraysFromMemory(array, rows);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				array[i][j] = arr[i][j];
			}
		}
		return array;
	}

	void defTaskOne(int** arr, const size_t rows, const size_t columns)
	{
		checkArraysFromMemory(arr, rows);

		for (size_t i = 0; i < rows; i++)
		{
			size_t idx = 0;
			int max = arr[i][0];

			for (size_t j = 0; j < columns; j++)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
					idx = j;
				}
			}

			arr[i][idx] = idx + 1;
		}

		printArrays(arr, rows, columns);
	}

	void defTaskTwo(int** arr, const size_t rows, const size_t columns)
	{
		checkArraysFromMemory(arr, rows);

		const int min = getMin(arr, rows, columns);
		const int count = count_getMin(arr, rows, columns, min);

		size_t newsize = rows + count;
		int** newarr = getMakeArrays(newsize, columns);
		checkArraysFromMemory(newarr, newsize);

		int* arr_rows = (int*)calloc(rows, sizeof(int));

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (arr[i][j] == min)
				{
					arr_rows[i] = 1;
				}
			}
		}



		size_t temp = 1;
		size_t idx = 0;
		for (size_t i = 0; i < rows; i++)
		{
			if (arr_rows[i] == 1)
			{
				for (size_t j = 0; j < columns; j++)
				{
					newarr[idx][j] = arr[i][j];
				}
				idx++;
				if (temp < rows)
				{
					for (size_t j = 0; j < columns; j++)
					{
						newarr[idx][j] = arr[temp][j];
					}
					idx++;
				}
				else
				{
					for (size_t j = 0; j < columns; j++)
					{
						newarr[idx][j] = 0;
					}
					idx++;
				}
				temp = temp + 2;
			}
			else
			{
				for (size_t j = 0; j < columns; j++)
				{
					newarr[idx][j] = arr[i][j];
				}
				idx++;
			}
		}

		printArrays(newarr, newsize, columns);
		free(arr_rows);
		freeArraysMemory(newarr, newsize);
	}

	const int getMin(int** arr, const size_t rows, const size_t columns)
	{
		checkArraysFromMemory(arr, rows);

		int min = arr[0][0];

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (arr[i][j] < min)
				{
					min = arr[i][j];
				}
			}
		}

		return min;
	}

	const int count_getMin(int** arr, const size_t rows, const size_t columns, const int min)
	{
		int count = 0;

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (arr[i][j] == min)
				{
					count++;
					break;
				}
			}
		}

		return count;
	}

	void ERROR(const char* text)
	{
		fprintf(stderr, "%s", text);
		exit(1);
	}

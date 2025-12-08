#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Находит сумму положительных элементов, значения которых состоят из двух цифр
 * @param arr массив
 * @param size размер массива
 */
void sumPositiveTwoDigit(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в диапазоне [-1000;1000]
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Умножает все четные положительные элементы на последний элемент массива
 * @param copyArr копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если не найдено четных положительных элементов
 */
int multiplyEvenPositiveByLast(int* copyArr, const size_t size);

/**
 * @brief Находит номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа
 * @param arr массив
 * @param size размер массива
 * @param threshold заданное число для сравнения
 * @return Возвращает индекс первого элемента пары, если пара найдена, -1 - если не найдена
 */
int findFirstPairIndex(int* arr, const size_t size, const int threshold);

/**
 * @brief RANDOM - заполнение массива случайными числами в диапазоне [-1000;1000]
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t size = getSize("Введите размер массива:\n");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти!");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n%d - случайными числами\n%d - вручную\n", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        srand(time(NULL));
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        fprintf(stderr, "Ошибка выбора.");
        free(arr);
        exit(1);
    }
    printf("\nИсходный массив:\n");
    printArray(arr, size);
    sumPositiveTwoDigit(arr, size);
    int* copyArr = copyArray(arr, size);
    int result = multiplyEvenPositiveByLast(copyArr, size);
    if (result == 1)
    {
        printf("Массив после умножения четных положительных элементов на последний элемент:\n");
        printArray(copyArr, size);
    }
    printf("\nВведите число для сравнения суммы пары: ");
    int threshold = Value();
    int pairIndex = findFirstPairIndex(arr, size, threshold);
    if (pairIndex != -1)
    {
        printf("Найдена пара: элементы [%d]=%d и [%d]=%d\n",
            pairIndex, arr[pairIndex], pairIndex + 1, arr[pairIndex + 1]);
        printf("Их сумма (%d) < %d\n", arr[pairIndex] + arr[pairIndex + 1], threshold);
    }
    else
    {
        printf("Пара соседних элементов с разными знаками и суммой меньше %d не найдена\n", threshold);
    }
    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        fprintf(stderr, "Ошибка ввода");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr, "Размер должен быть положительным!");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент %zu (диапазон [-1000;1000]): ", i + 1);
        arr[i] = Value();
        if (arr[i] < -1000 || arr[i] > 1000)
        {
            printf("Элемент вне допустимого диапазона [-1000;1000]!\n");
            i--;
        }
    }
}

void fillRandom(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 2001 - 1000;
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumPositiveTwoDigit(int* arr, const size_t size)
{
    int sum = 0;
    int found = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] >= 10 && arr[i] <= 99)
        {
            sum += arr[i];
            found = 1;
        }
    }
    if (found)
    {
        printf("Сумма положительных двузначных элементов: %d\n", sum);
    }
    else
    {
        printf("Положительных двузначных элементов не найдено\n");
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти для копии массива");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int multiplyEvenPositiveByLast(int* copyArr, const size_t size)
{
    if (size == 0)
    {
        printf("Массив пуст\n");
        return 0;
    }
    int lastElement = copyArr[size - 1];
    int modified = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if (copyArr[i] > 0 && copyArr[i] % 2 == 0)
        {
            copyArr[i] *= lastElement;
            modified = 1;
        }
    }
    if (!modified)
    {
        printf("Четных положительных элементов для умножения не найдено\n");
        return 0;
    }

    return 1;
}

int findFirstPairIndex(int* arr, const size_t size, const int threshold)
{
    if (size < 2)
    {
        return -1;
    }
    for (size_t i = 0; i < size - 1; i++)
    {
        int current = arr[i];
        int next = arr[i + 1];
        if ((current > 0 && next < 0) || (current < 0 && next > 0))
        {
            if (current + next < threshold)
            {
                return (int)i;
            }
        }
    }

    return -1;
}
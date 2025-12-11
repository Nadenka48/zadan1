#pragma warning(disable:4996)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief ищет сумму положительных двузначных элементов массива
 * @param arr массив
 * @param size размер массива
 * @return 1 - если функция выполнена корректно, иначе 1
 */
int getSum2Digit(const int* arr, const size_t size);

/**
 * @brief умножает все чётные положительные элементы массива на последний элемент массива
 * @param copyArr копия массива
 * @param size размер массива
 * @return 1 - если функция выполнена корректно, иначе 0
 */
int multAllPosEvenWithLastDigit(int* copyArr, const size_t size);

/**
 * @brief ищет номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа
 * @param copyArr копия массива
 * @param size размер массива
 * @return 1 - если программа выполнена корректно, иначе 0
 * @note здесь работа происходит не с изначальным массивом, а с уже изменённой выше копией этого массива
 * для понимания касаемо номеров пары элементов: есть пара - нулевой и первый элемент массива, следовательно это первая пара.
 * вторая пара - это первый и второй элемент массива. На этих примерах видно, что номер пары определяется номером
 * второго элемента этой пары
 */
int FindNumberFirstDifPairWhichSumLessDigit(const int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
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
    size_t size = getSize("Input size of an array:\n");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Error");
        exit(1);
    }
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        fprintf(stderr, "Error.");
        free(arr);
        exit(1);
    }
    printArray(arr, size);
    printf("\n");
    getSum2Digit(arr, size);
    printf("\n");
    int* copyArr = copyArray(arr, size);
    multAllPosEvenWithLastDigit(copyArr, size);
    FindNumberFirstDifPairWhichSumLessDigit(copyArr, size);
    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        fprintf(stderr, "Input error");
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
        fprintf(stderr, "Input error");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array:", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    printf("Your array is:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    printf("diapozon start:\n");
    int start = Value();
    printf("diapozon end:\n");
    int end = Value();
    if (start > end) {
        fprintf(stderr, "Error: start cannot be greater than end\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL)
    {
        fprintf(stderr, "Error");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int getSum2Digit(const int* arr, const size_t size) {
    int sum = 0; //счётчик для определения, выполнена ли операция хотя бы раз
    for (size_t i = 0; i < size; i++) {
        if (arr[i] >= 10 && arr[i] <= 99) {
            sum += arr[i];
        }
    }
    if (sum == 0) {
        printf("No relevant elements.\n");
        return 0;
    }
    printf("Sum of positive 2-digit numbers is %d.\n", sum);
    return 1;
}

int multAllPosEvenWithLastDigit(int* copyArr, const size_t size) {
    int k = 0;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] % 2 == 0 && copyArr[i] > 0) {
            copyArr[i] *= copyArr[size - 1];
            k++;
        }
    }
    if (k == 0) {
        printf("No elements to exchange.\n");
        return 0;
    }
    printArray(copyArr, size);
    return 1;
}

int FindNumberFirstDifPairWhichSumLessDigit(const int* copyArr, const size_t size) {
    bool k = false; //сделано наподобие счётчиков в предыдущем задании, просто когда надо сделать что-то единоразово, мне удобнее писать через него.
    printf("Input any number:\n");
    const int a = Value();
    for (size_t i = 0; i < size - 1; i++) {
        if ((copyArr[i] < 0 && copyArr[i + 1] > 0 || copyArr[i] > 0 && copyArr[i + 1] < 0) && copyArr[i] + copyArr[i + 1] < a) {
            printf("Number of pair is %zu\n", i + 1);
            k = true;
            break;
        }
    }
    if (k == false) {
        printf("No relevant pairs.");
        return 0;
    }
    return 1;
}

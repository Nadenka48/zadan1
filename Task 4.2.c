#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<stdbool.h>

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

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
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяется первый элемент кратный 5 нулем
 * @param copyArr копия массива
 * @param size размер массива
 */
void replaceFive(int* copyArr, const size_t size);

/**
 * @brief Вставляет элемент со значением К после всех нечетных элементов, начинающихся на К
 * @param copyArr копия массива
 * @param size размер массива
 */
int insertK(const int* copyArr, const size_t size);

/**
 * @brief Создает новый массив М из элементов старого массива Р
 * @param copyArr копия массива
 * @param size размер массива
 */
int MArray(const int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };


/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }

    printf("Выберите способ заполнения массива:\n""%d-случайными числами %d-вручную ", RANDOM, MANUAL);
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
        printf("error");
        free(arr);
        break;

    }


    printArray(arr, size);
    int* copyArr = copyArray(arr, size);

    replaceFive(copyArr, size);
    printArray(copyArr, size);


    insertK(copyArr, size);
    MArray(copyArr, size);

    free(copyArr);
    free(arr);

    return 0;
}


int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}


size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}



void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите A = ");
        arr[i] = Value();
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



void fillRandom(int* arr, const size_t size)
{
    printf("начальное значение диапазона: ");
    int start = Value();
    printf("конечное значение диапазона: ");
    int end = Value();
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}


int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}


void replaceFive(int* copyArr, const size_t size)
{
    bool Find5 = false;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] % 5 == 0) {
            printf("Замена на 0 произведена: ");
            Find5 = true;
            copyArr[i] = 0;
            break;
        }
    }
    if (Find5 != true) {
        printf("Число кратное 5 не найдено \n");
    }
}


int insertK(const int* copyArr, const size_t size)
{
    printf("Введите значение K: ");
    int K = Value();
    int firstDigitK = abs(K);
    while (firstDigitK >= 10) {
        firstDigitK /= 10;
    }


    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        int firstDigit = abs(copyArr[i]);
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }


        if (copyArr[i] % 2 != 0 && (firstDigit == firstDigitK))
        {
            count++;
        }
    }
    if (count == 0)
    {
        printf("Элементов, начинающихся на цифру %d, нет.\n", firstDigitK);
        abort();
    }


    size_t newSize = size + count;
    int* newArr = malloc(newSize * sizeof(int));
    if (newArr == NULL)
    {
        printf("Error\n");
        exit(1);
    }


    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        int firstDigit = abs(copyArr[i]);
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }

        if (copyArr[i] % 2 != 0 && (firstDigit == firstDigitK))
        {
            newArr[j++] = copyArr[i];
            newArr[j++] = K;
        }
        else
        {
            newArr[j++] = copyArr[i];
        }
    }
    printf("Новый массив с К: ");
    printArray(newArr, newSize);

    free(newArr);
    return 1;
}



int MArray(const int* copyArr, const size_t size)
{
    if (size == 0)
    {
        printf("Массив P пуст, нельзя сформировать новый массив!\n");
        abort();
    }
    int* M = malloc(size * sizeof(int));
    if (M == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        M[i] = copyArr[i] * (i + 1);
    }
    M[0] = 0;
    M[size - 1] = 0;

    printf("Новый массив М: ");
    printArray(M, size);
    free(M);
    return 1;
}
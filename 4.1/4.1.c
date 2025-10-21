#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

size_t getSize();

void fillArray(int* arr, const size_t size);
void printArray(int* arr, const size_t size);
int sumArray(int* arr, const size_t size);
void sortArry(int* arr, const size_t size);
int sumNchetn(int* arr, const size_t size);
void fillRandom(int* arr, const size_t size);
int* copyArray(const int* arr, const size_t size);
void replaceEvenElements(int* copyArr, const size_t size);

enum {RANDOM = 1, MANUAL};

int main()
{
    printf("Введите размер массива:  ");
    size_t size = getSize();
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
            "%d случайными числамиб %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
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
    //printf("\nsum = %d", sumArray(arr, size));
    //sortArry(arr, size);
    //printf("\n%d", sumNchetn(arr, size));
    int* copyArr = copyArray(arr,size);
    replaceEvenElements(copyArr, size);
    printArray(copyArr,size);
    free(copyArray);
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

size_t getSize()
{
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
        printf("Vvedite A = ");
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int sumArray(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result += arr[i];
    }
    return result;
}

void sortArry(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}

int sumNchetn(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 1)
            {
                result += arr[i];
            }
    }
    return result;
}

void fillRandom(int* arr, const size_t size)
{
    printf("diapozon start ");
    int start = Value();
    printf("diapozon end ");
    int end = Value();
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
    for (size_t i =0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void replaceEvenElements(int* copyArr, const size_t size)
{
    for (size_t i = 0; i<size; i++)
    {
        if (copyArr[i] % 2 == 0)
        {
            copyArr[i]*=-1;
        }
}

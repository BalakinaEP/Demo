#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();
size_t getSize(char* message);
void fillArray(int** arr, const size_t rows,const size_t columns);
void printArray(int** arr, const size_t rows,const size_t columns);
int sumArray(int** arr, const size_t rows, const size_t columns, const size_t row);
void fillRandom(int** arr, const size_t rows,const size_t columns);
int** getArray(const size_t rows, const size_t columns);
void checkRange(const int start, const int end);
void chekrow(const size_t row, const size_t rows);
int** freeArray(int** arr, const size_t rows);
void deleteRowsEvenSum(int** arr, const size_t rows, const size_t columns,int** newarr);
int getCountEvenSumElemOfRows(int** arr, const size_t rows, const size_t columns );



enum {RANDOM = 1, MANUAL};

int main()
{
    
    size_t rows = getSize("Введите количество строк массива:  ");
    size_t columns = getSize("Введите количество стобцов массива:  ");
    int** arr = getArray(rows,columns);
    printf("Выберите способ заполнения массива:\n"
            "%d случайными числамиб %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, rows, columns);
                break;
            case MANUAL:
                fillArray(arr, rows, columns);
                break;
            default:
                printf("error");
                free(arr);
                break;
        }

    
    printArray(arr, rows, columns);
    size_t row = getSize("Введите номер строки для поиска суммы элементов:") - 1;
    chekrow(row, rows);
    printf("Cумма элементов в  строке %d равна %d\n",row + 1,sumArray(arr, rows, columns, row));
    size_t newrows = rows - getCountEvenSumElemOfRows(arr, rows, columns);
    int** newarr = getArray(newrows,columns);
    deleteRowsEvenSum(arr, rows, columns, newarr);
    printArray(newarr,newrows,columns);
    freeArray(newarr, newrows);
    freeArray(arr, rows);
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

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j<columns; j++)
        {
            printf("Введите a[%d,%d] = ",i,j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j=0; j<columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int sumArray(int** arr, const size_t rows, const size_t columns, const size_t row)
{
    int result = 0;
    for (size_t i = 0; i < columns; i++)
    {
        result += arr[row][i];
    }
    return result;
}

void fillRandom(int** arr, const size_t rows,const size_t columns)
{
    printf("Введите начало диапазона случайных чисел");
    int start = Value();
    printf("Введите конец диапазона случайных чисел");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ )
    {
        arr[i] = malloc(columns * sizeof(int));
    }
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    return arr;
}
int** freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i<rows; i++ )
    {
        free(arr[i]);
    }
    free(arr);
}

void checkRange(const int start, const int end)
{
    if(start > end)
    {
        printf("Error\n");
        exit(1);
    }
}

void chekrow(const size_t row, const size_t rows)
{
        if(row > rows)
    {
        printf("Error\n");
        exit(1);
    }
}

int getCountEvenSumElemOfRows(int** arr, const size_t rows, const size_t columns )
{
    int count = 0;
    for ( size_t i =0; i<rows;i++)
    {
        int sum = 0;
        for ( size_t j =0; j<columns;j++)
        {
            sum += arr[i][j];
        }
        if (sum % 2 == 0)
            {
                count++;
            }
    }
    return count;
    
}

void deleteRowsEvenSum(int** arr, const size_t rows, const size_t columns,int** newarr)
{
    size_t myi = 0;
    for ( size_t i =0; i<rows;i++)
    {
        int sum = 0;
        for ( size_t j =0; j<columns;j++)
        {
            sum += arr[i][j];
        }
        if (sum % 2 != 0)
            {
               for ( size_t j =0; j<columns;j++)
               {
                   newarr[myi][j]=arr[i][j];
               }
               myi++;
            }
    }
}

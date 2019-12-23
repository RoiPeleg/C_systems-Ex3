#include "isort.h"
#include <stdio.h>
void shift_element(int *arr, int i)
{
    int *next = (arr) + 1;
    int temp = *next;
    int temp2 = 0;
    for (int j = 0; j < i; j++)
    {
        arr++;
        next = arr + 1;
        temp2 = *next;
        *next = temp;
        temp = temp2;
    }
}

void insertion_sort(int *arr, int len)
{
    int *arr2 = arr+1;
    int *arr3 = arr2;
    for (int i = 1; i < len; i++)
    {
        int counter = 0;
        int num = *arr3;
        arr3--;
        while (arr3!=arr-1&&(*(arr3)>num))
        {
            counter++;
            arr3--;
        }
        shift_element(arr3,counter);
        *(arr3+1) = num;
        arr2++;
        arr3 = arr2;
    }
}

void print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            printf("%d", *arr);
        }
        else
        {
            printf("%d,", *arr);
        }
        (arr++);
    }
    arr = arr - len;
}
int main()
{
    int arr[size] = {0};
    int *arr2 = arr;
    for (int i = 0; i < size; i++)
    {

        scanf(" %d", &*arr2);
        arr2++;
    }
    arr2 = arr2 - size;
    insertion_sort(arr2,size);
    print(arr2, size);
}
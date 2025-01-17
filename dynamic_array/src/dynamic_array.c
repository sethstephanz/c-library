#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

// Dynamic array that doubles in size if more elements are added.

int main()
{
    return EXIT_SUCCESS;
}

DynamicArray *create_array(int initial_length)
{
    DynamicArray *arr = (DynamicArray *)malloc(arr->size * sizeof(int));
    if (!arr)
    {
        perror("Failed to allocate memory for array");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->data = (int *)malloc(initial_length * sizeof(int)); // this cast is unecessary in C, but is in C++
    if (!arr->data)
    {
        perror("Failed to allocate memory for data");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->size = 0;
    arr->length = initial_length;
    return arr;
}

void resize_array(DynamicArray *arr)
{
    arr->length *= 2;
    arr->data = (int *)realloc(arr->data, arr->length * sizeof(int));
    if (!arr->data)
    {
        perror("Resize_array: Failed to reallocate memory for data");
        exit(EXIT_FAILURE);
    }
}

void free_array(DynamicArray *arr)
{
    free(arr->data);
    free(arr);
}

void print_array(DynamicArray *arr)
{
    printf("Array (size: %d, length: %d): ", arr->size, arr->length);
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void append(DynamicArray *arr, int el)
{
    if (arr->size >= arr->length)
    {
        resize_array(arr);
    }

    // add element and increase size
    arr->data[arr->size++] = el;
}

void insert(DynamicArray *arr, int el, int idx)
{
    if (arr->size == arr->length)
    {
        resize_array(arr);
    }
    if (idx >= 0 && idx < arr->length)
    {
        // shift over elements from size of array + 1 to idx
        int i;
        for (i = arr->length; i > idx; i--)
        {
            arr->data[i] = arr->data[i - 1];
        }

        // insert el at idx
        arr->data[idx] = el;
        arr->size++;
    }
    else
    {
        printf("Insert: Invalid index\n");
    }
}

void delete(DynamicArray *arr, int idx)
{
    if (idx >= 0 && idx <= arr->size)
    {
        for (int i = idx; i < arr->length - 1; i++)
        {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    }
    else
    {
        printf("Delete: Invalid index\n");
    }
}

int search(DynamicArray *arr, int el)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->data[i] == el)
        {
            return i - 1;
        }
    }
    return -1;
}

int get(DynamicArray *arr, int idx)
{
    if (idx >= 0 && idx <= arr->size)
    {
        return arr->data[idx];
    }
    else
    {
        printf("Get: Invalid index\n");
        return -1;
    }
}

void set(DynamicArray *arr, int idx, int val)
{
    if (idx >= 0 && idx <= arr->size)
    {
        arr->data[idx] = val;
    }
    else
    {
        printf("Set: Invalid index\n");
    }
}

float avg(DynamicArray *arr)
{
    if (arr->size == 0)
    {
        printf("Avg: No elements in array\n");
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < arr->size; i++)
    {
        sum += arr->data[i];
    }
    float avg = sum / arr->size;
    return avg;
}

int max(DynamicArray *arr)
{
    // TODO: Figure out better way to handle no values.
    if (arr->size == 0)
    {
        printf("Max: No elements in array\n");
        return -1;
    }

    int max = arr->data[0];
    for (int i = 1; i < arr->size; i++)
    {
        if (max < arr->data[i])
        {
            max = arr->data[i];
        }
    }
    return max;
}

int min(DynamicArray *arr)
{
    // TODO: Figure out better way to handle no values.
    if (arr->size == 0)
    {
        printf("Min: No elements in array\n");
        return -1;
    }

    int min = arr->data[0];
    for (int i = 1; i < arr->size; i++)
    {
        if (min > arr->data[i])
        {
            min = arr->data[i];
        }
    }
    return min;
}

int sum(DynamicArray *arr)
{
    // TODO: Figure out better way to handle no values.
    if (arr->size == 0)
    {
        printf("Sum: No elements in array\n");
        return -1;
    }

    int sum = arr->data[0];
    for (int i = 1; i < arr->size; i++)
    {
        sum += arr->data[i];
    }
    return sum;
}

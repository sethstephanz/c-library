#include <stdio.h>
#include <stdlib.h>

// Dynamic array that doubles in size if more elements are added.

typedef struct
{
    int *data;
    int size;   // number of places in memory in array
    int length; // number of elements in the array
} DynamicArray;

// init & utility functions
DynamicArray *create_array(int initial_length); // initialize dynamic array
void free_array(DynamicArray *arr);             // free memory allocated for array
void print_array(DynamicArray *arr);            // print contents from array
void resize_array(DynamicArray *arr);           // doubles size of array if run out of room

// methods
void append(DynamicArray *arr, int el);          // append element to dynamic array
void insert(DynamicArray *arr, int el, int idx); // insert element at index
void delete(DynamicArray *arr, int idx);         // delete element by index
int search(DynamicArray *arr, int el);           // search for element. returns first index found
int get(DynamicArray *arr, int idx);             // return value of element at index
void set(DynamicArray *arr, int idx, int val);   // replace value of element at index with provided value
float avg(DynamicArray *arr);                    // return average of values in array
int max(DynamicArray *arr);                      // return maximum value in array
int min(DynamicArray *arr);                      // return minimum value in array
int sum(DynamicArray *arr);                      // return sum of values in array

int main()
{
    DynamicArray *arr = create_array(5);

    // test
    // test append, insert, delete, print_array
    // int i = 0;
    // for (; i < 5; i++)
    // {
    //     append(arr, i + 1);
    //     print_array(arr);
    // }

    // insert(arr, 100, 0);
    // print_array(arr);

    // for (; i < 10; i++)
    // {
    //     append(arr, i + 1);
    //     print_array(arr);
    // }

    // delete (arr, 0);
    // print_array(arr);
    // delete (arr, 100);
    // print_array(arr);

    // insert(arr, 1, 0);

    // // test search, get, set, avg, max, min, sum
    // printf("Index of 5: %d\n", search(arr, 5));       // 4
    // printf("Index of 1000: %d\n", search(arr, 1000)); // not found

    // printf("Get index 0: %d\n", get(arr, 0));
    // printf("Get invalid index: %d\n", get(arr, 500));

    // printf("Avg of non-empty arr: %f\n", avg(arr));
    // printf("Max of non-empty arr: %d\n", max(arr));
    // printf("Min of non-empty arr: %d\n", min(arr));
    // printf("Sum of non-empty arr: %d\n", sum(arr));

    // DynamicArray *empty_arr = create_array(5); // create blank array

    // printf("Avg of empty arr: %f\n", avg(empty_arr));
    // printf("Max of empty arr: %d\n", max(empty_arr));
    // printf("Min of empty arr: %d\n", min(empty_arr));
    // printf("Sum of empty arr: %d\n", sum(empty_arr));

    free_array(arr);
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

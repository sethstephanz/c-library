#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

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

#endif // DYNAMIC_ARRAY_H
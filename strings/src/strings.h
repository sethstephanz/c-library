#ifndef STRINGS_H
#define STRINGS_H
#include <ctype.h>
#include <stdbool.h>

#define MAX_STR_LEN 10000

typedef struct {
    char *data;
    int capacity; // number of places in memory in array
    int length;   // number of elements in the array
} String;

// init & utility functions
String *str(char *raw_str);  // initialize string
void free_str(String *str);  // free memory allocated for array
void print_str(String *str); // print contents from array

// string methods
int len(String *str);                                                    // return length of string
int lower(String *str);                                                  // convert all chars in string to lower case
int upper(String *str);                                                  // convert all chars in string to upper case
int ltrim(String *str);                                                  // trim white space from left
int rtrim(String *str);                                                  // trim white space from right
int trim(String *str);                                                   // trim white space from left and right
int strip(String *str, char *delimeter);                                 // strip white space from string
int rstrip(String *str, char *delimeter);                                // trim white space from right of string
int lstrip(String *str, char *delimeter);                                // trim white space from left of string
bool is_alpha(String *str);                                              // detect if all chars in string are alpha characters
bool is_digit(String *str);                                              // detect if all chars in string are digits 0-9
size_t find(String *str, char *to_find);                                 // find first instance (idx) of character
size_t replace(String *str, char *to_replace, char *replace_with);       // replace first instance of character in string
int split(String *str, char *delimeter, String **out_arr, int *out_cnt); // split string

int join(String *str, char *delimeter); // string will be joined using token
int reverse(String *str);               // reverses string

#endif // STRINGS_H
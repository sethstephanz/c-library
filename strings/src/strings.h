#ifndef STRINGS_H
#define STRINGS_H
#include <ctype.h>
#include <stdbool.h>

#define MAX_STR_LEN 10000

typedef struct {
    int *data;
    int capacity; // number of places in memory in array
    int length;   // number of elements in the array
} String;

// init & utility functions
String *create_string(int initial_length); // initialize string
void free_string(String *str);             // free memory allocated for array
void print(String *str);                   // print contents from array

size_t len(char *str);                                           // return length of string. -1 if invalid entry
int lower(char *str);                                            // convert all chars in string to lower case
int upper(char *str);                                            // convert all chars in string to upper case
int ltrim(char *str);                                            // trim white space from left
int rtrim(char *str);                                            // trim white space from right
int trim(char *str);                                             // trim white space from left and right
int strip(char *str, char *delimeter);                           // strip white space from string
int rstrip(char *str, char *delimeter);                          // trim white space from right of string
int lstrip(char *str, char *delimeter);                          // trim white space from left of string
bool is_alpha(char *str);                                        // detect if all chars in string are alpha characters
bool is_digit(char *str);                                        // detect if all chars in string are digits 0-9
size_t find(char *str, char *to_find);                           // find first instance (idx) of character
size_t replace(char *str, char *to_replace, char *replace_with); // replace first instance of character in string
int split(char *str, char *delimeter);                           // split string on
int join(char *str, char *token, char *delimeter);               // string will be joined using token

#endif // STRINGS_H
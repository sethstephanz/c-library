#ifndef STRINGS_H
#define STRINGS_H
#include <ctype.h>
#include <stdbool.h>

size_t len(char *str); // return length of string. -1 if invalid entry
void lower(char *str); // convert all chars in string to lower case
void upper(char *str); // convert all chars in string to upper case
void ltrim(char *str); // trim white space from left
void rtrim(char *str); // trim white space from right
void trim(char *str); // trim white space from left and right
void strip(char *str, char *delimeter);                          // strip white space from string
void rstrip(char *str, char *delimeter);                         // trim white space from right of string
void lstrip(char *str, char *delimeter);                         // trim white space from left of string
bool is_alpha(char *str);                                        // detect if all chars in string are alpha characters
bool is_digit(char *str);                                        // detect if all chars in string are digits 0-9
size_t find(char *str, char *to_find);                           // find first instance (idx) of character
size_t replace(char *str, char *to_replace, char *replace_with); // replace first instance of character in string
void split(char *str, char *delimeter);                          // split string on
void join(char *str, char *token, char *delimeter);              // string will be joined using token

#endif // STRINGS_H
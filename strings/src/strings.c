#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: these string methods will modify the string directly.
// Create a copy if need to keep original!

// 'a' - 'z' = 97 - 122
// 'A' - 'Z' = 65 - 90

size_t len(char *str) {
    if (!str)
        return (size_t)-1;

    size_t s = 0;
    while (str[s] != '\0') {
        s++;
    }
    return s;
}

void lower(char *str) {
    size_t s = 0;
    while (str[s] != '\0') {
        int ascii = (int)str[s];
        if (ascii >= 65 && ascii <= 90) {
            str[s] = str[s] + 32;
        }
        s++;
    }
}

void upper(char *str) {
    size_t s = 0;
    while (str[s] != '\0') {
        int ascii = (int)str[s];
        if (ascii >= 97 && ascii <= 122) {
            str[s] = str[s] - 32;
        }
        s++;
    }
}

void ltrim(char *str) {
    int l = 0;
    int r = 0;
    while (isspace(str[r])) {
        r++;
    }
    while (str[r] != '\0') {
        str[l] = str[r];
        l++;
        r++;
    }
}

// void rtrim(char *str) {}

// void trim(char *str) {
// ltrim(str);
// rtrim(str);
// }

// void lstrip(char *str, char *delimeter) {
// int l = 0;
// int r = 0;
// while () {
// r++;
// }
// printf("str[r] = %c\n", str[r]);
// while (str[r] != '\0') {
// str[l] = str[r];
// l++;
// r++;
// }
// }

// void rstrip(char *str);

// void strip(char *str) {
// lstrip(str);
// rstrip(str);
// }

// size_t isalpha();
// size_t isdigit();
// size_t find();
// size_t replace()
// void split();
// void join();

#include "strings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: Most of these string methods will modify the string directly.
// Create a copy if need to keep original!

// 'a' - 'z' = 97 - 122
// 'A' - 'Z' = 65 - 90

String *create_string(int str_length) {
    if (str_length >= MAX_STR_LEN) { // too large or no room for null terminator
        fprintf(stderr, "Max string length is 10000 characters\n");
        exit(EXIT_FAILURE);
    }
    String *str = (String *)malloc(sizeof(String));
    if (!str) {
        fprintf(stderr, "Failed to allocate memory for string\n");
        exit(EXIT_FAILURE);
    }

    str->data = (char *)malloc(str_length * sizeof(char)); // this cast is unecessary in C, but is in C++
    if (!str->data) {
        perror("Failed to allocate memory for data\n");
        free(str);
        exit(EXIT_FAILURE);
    }
    str->size = 0;
    str->length = str_length;
    return str;
}

void free_string(String *str) {
    free(str->data);
    free(str);
}

void print_string(String *str) {
    printf("Array (size: %d, length: %d): ", str->size, str->length);
    for (int i = 0; i < str->size; i++) {
        printf("%d ", str->data[i]);
    }
    printf("\n");
}

int lower(char *str) {
    if (!str) {
        return -1;
    }
    size_t s = 0;
    while (str[s] != '\0') {
        int ascii = (int)str[s];
        if (ascii >= 65 && ascii <= 90) {
            str[s] = str[s] + 32;
        }
        s++;
    }
    return 0;
}

int upper(char *str) {
    if (!str) {
        return -1;
    }
    size_t s = 0;
    while (str[s] != '\0') {
        int ascii = (int)str[s];
        if (ascii >= 97 && ascii <= 122) {
            str[s] = str[s] - 32;
        }
        s++;
    }
    return 0;
}

int ltrim(char *str) {
    if (!str || len(str) <= 0) {
        return -1;
    }
    int l = 0;
    int r = 0;
    while (isspace(str[r])) {
        r++;
    }
    while (str[r] != '\0') {
        str[l++] = str[r++];
    }
    str[l] = '\0';
    return 0;
}

int rtrim(char *str) {
    int r = len(str);
    if (!str || r <= 0) {
        return -1;
    }
    while (isspace(str[r])) {
        r--;
    }
    str[r] = '\0';
    return 0;
}

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

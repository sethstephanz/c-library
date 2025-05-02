#include "strings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: Most of these string methods will modify the string directly.
// Create a copy if need to keep original!

// 'a' - 'z' = 97 - 122
// 'A' - 'Z' = 65 - 90

String *str(char *raw_str) {
    int str_length = strlen(raw_str);

    if (str_length >= MAX_STR_LEN) { // too large or no room for null terminator
        fprintf(stderr, "Max string length is 10000 characters\n");
        exit(EXIT_FAILURE);
    }

    String *str = malloc(sizeof(String));
    if (!str) {
        fprintf(stderr, "Failed to allocate memory for string\n");
        exit(EXIT_FAILURE);
    }

    // Allocate space for null terminator
    str->data = malloc((str_length + 1) * sizeof(char));
    if (!str->data) {
        fprintf(stderr, "Failed to allocate memory for data\n");
        free(str);
        exit(EXIT_FAILURE);
    }

    strcpy(str->data, raw_str); // copy string including null terminator
    str->length = str_length;
    str->capacity = str_length + 1; // total allocated size

    return str;
}

int len(String *str) {
    if (!str) {
        return -1;
    }
    return str->length - 1;
}

void free_str(String *str) {
    free(str->data);
    free(str);
}

void print_str(String *str) {
    printf("Array (size: %d, length: %d): ", str->capacity, str->length);
    for (int i = 0; i < str->capacity; i++) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

int lower(String *str) {
    if (!str) {
        return -1;
    }
    char *str_data = str->data;
    size_t s = 0;
    while (str_data[s] != '\0') {
        int ascii = (int)str_data[s];
        if (ascii >= 65 && ascii <= 90) {
            str_data[s] = str_data[s] + 32;
        }
        s++;
    }
    return 0;
}

int upper(String *str) {
    if (!str) {
        return -1;
    }
    char *str_data = str->data;
    size_t s = 0;
    while (str_data[s] != '\0') {
        int ascii = (int)str_data[s];
        if (ascii >= 97 && ascii <= 122) {
            str_data[s] = str_data[s] - 32;
        }
        s++;
    }
    return 0;
}

int ltrim(String *str) {
    if (!str || len(str) < 0) {
        return -1;
    }

    char *str_data = str->data;
    int l = 0;
    int r = 0;
    while (isspace(str_data[r])) {
        r++;
    }
    while (str_data[r] != '\0') {
        str_data[l++] = str_data[r++];
    }
    str_data[l] = '\0';
    return 0;
}

int rtrim(String *str) {
    if (!str || len(str) < 0 || !str->data) {
        return -1;
    }

    char *str_data = str->data;
    int r = str->length - 1;

    while (r >= 0 && isspace((unsigned char)str_data[r])) {
        r--;
    }
    str_data[r + 1] = '\0';
    str->length = r + 1;
    return 0;
}

int trim(String *str) {
    if (ltrim(str) < 0 || rtrim(str) < 0) {
        return -1;
    }
    return 0;
}

int split(String *str, char *delimeter, String **out_arr, int *out_cnt) {
    if (!str || !delimeter || !out_arr || !out_cnt) {
        return -1;
    }

    int max_tokens = 10;
    String *results = malloc(sizeof(String) * max_tokens);
    if (!results) {
        return -1;
    }

    int count = 0;
    char *start = str->data;

    int str_len = len(str);

    while (start != '\0' && start < str_len) {
        }

    return 0;
}

// int join(String *str, char *delimeter);
// size_t isalpha();
// size_t isdigit();
// size_t find();
// size_t replace()

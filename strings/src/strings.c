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
    str->data[str_length] = '\0';   // guarantee null terminator
    return str;
}

size_t len(String *str) {
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
    printf("String (size: %d, length: %d): ", str->capacity, str->length);
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
    str->length = l - 1;
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
    str->data[r + 1] = '\0';
    str->length = r + 1;
    return 0;
}

int trim(String *str) {
    if (ltrim(str) < 0 || rtrim(str) < 0) {
        return -1;
    }
    return 0;
}

int split(String *to_split, char *delimiter, String **out_arr, int *out_cnt) {
    // Takes in string struct, tokenizes data, converts
    // tokens to Strings, returns array of String pointers
    if (!to_split || !delimiter || !out_cnt || !out_arr) {
        return -1;
    }

    int cnt = 0;
    char *saveptr;
    char *tok = strtok_r(to_split->data, delimiter, &saveptr);

    while (tok != NULL) {
        // strtok_r adds null terminator to end of each token
        // so fine to call str() on token
        out_arr[cnt++] = str(tok);
        tok = strtok_r(NULL, delimiter, &saveptr);
    }

    *out_cnt = cnt;
    return 0;
}

void print_str_explicit(char *str) {
    // Prints string with spaces replaced with characters
    // so can visually inspect them
    if (!str) {
        return;
    }
    for (int i = 0; i < (int)strlen(str); i++) {
        if (isspace(str[i])) {
            fprintf(stderr, "#");
        } else {
            fprintf(stderr, "%c", str[i]);
        }
    }
    fprintf(stderr, "\n");
}

int check_nt(String *str) {
    // Checks that end of string is null terminated
    if (!str || !str->data) {
        return -1;
    }

    int str_len = len(str);
    if (str->data[str_len + 1] != '\0') {
        return 0;
    } else {
        return 1;
    }
}

int reverse(String *str) {
    if (!str || !str->data) {
        return -1;
    }
    int l = 0;
    int r = len(str);

    while (l <= r) {
        char temp = str->data[l];
        str->data[l] = str->data[r];
        str->data[r] = temp;
        l++;
        r--;
    }
    return 0;
}

int join(String **to_join, char *delimeter, String *out_str, int arr_size) {
    // take in array of Strings
    // copy all Strings' data to a big buffer, nt at end
    // wrap the buffer and return
    // final buffer size will be len of strings to join + (length of delimeter * number of strings - 1)

    if (!to_join || !delimeter || arr_size <= 0 || !out_str) {
        fprintf(stderr, "join1\n");
        return -1;
    }

    fprintf(stderr, "join\n");
    size_t del_len = (size_t)strlen(delimeter);
    size_t total_len = 0;

    for (int i = 0; i < arr_size; i++) {
        total_len += len(to_join[i]);
        if (i < arr_size - 1) {
            total_len += del_len;
        }
    }

    char *buffer = malloc(total_len + 1);
    if (!buffer) {
        return -1;
    }

    buffer[0] = '\0';

    for (int i = 0; i < arr_size; i++) {
        strcat(buffer, to_join[i]->data);
    }

    out_str = str(buffer);
    free(buffer);
    return 0;
}

// size_t isalpha();
// size_t isdigit();
// size_t find();
// size_t replace();
// size_t replace_all();

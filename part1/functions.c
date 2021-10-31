#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


//for random array
#define n 100
#define MIN -500
#define MAX 1000

int compare_int(const void *a, const void *b) {
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    return 0;
}

int compare_float(const void *a, const void *b) {
    if(*(float*)a > *(float*)b) return 1;
    else if(*(float*)a < *(float*)b) return -1;
    return 0;
}

int compare_char(const void *a, const void *b) {
    if(*(char*)a > *(char*)b) return 1;
    else if(*(char*)a < *(char*)b) return -1;
    return 0;
}

int compare_string(const void *a, const void *b) {
    #define str1 *(char**)a
    #define str2 *(char**)b
    if (strlen(str1) > strlen(str2)) return 1;
    else if (strlen(str1) < strlen(str2)) return -1;
    return 0;
}

void test_int_rnd() {
    int* arr;
    
    srand(time(NULL));
    arr = calloc(n, sizeof(int));
    printf("src array:\n");
    for(int i=0;i<n;i++) {
        arr[i] = rand() % MAX + (MIN);
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    bubblesort(arr, n, sizeof(int), compare_int);
    //sort_t(arr, n, sizeof(int), compare_int);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_float_rnd() {
    float* arr;
    float rnd_tmp;
    srand(time(NULL));
    arr = calloc(n, sizeof(float));
    printf("src array:\n");
    for(int i=0;i<n;i++) {
        rnd_tmp = sin(rand() * rand());
        arr[i] = MIN + (MAX - MIN) * fabs(rnd_tmp);
        printf("%g ", arr[i]);
    }
    printf("\n\n");
    bubblesort(arr, n, sizeof(float), compare_float);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%g ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_char_rnd() {
    char *arr;
    srand(time(NULL));
    arr = calloc(n, sizeof(char));
    printf("src array:\n");
    for(int i=0;i<n;i++) {
        //arr[i] = rand() % 255 + (0);
        arr[i] = rand() % 90 + 26;
        //printf("%d = %c |",arr[i], arr[i]);
        printf("%c ", arr[i]);
    }
    printf("\n\n");
    bubblesort(arr, n, sizeof(char), compare_char);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_string() {
    const char *str[] = {
        "a", "vbudsbv", "ab", "fkbnfjwenvoidhrfio ofierhio irejogvierj ioerjghgiush459830 ghiwuh", "abc",
        "asdfghjkjlkl", "fmnaijbnigtoufwe ibgibgio", "nguirtdhe iuhuihiurthg hiurtohg bigwsoig iuguierwso hg",
        "", "qwerty", "zxc", "qwe", "bndoj hjytiorn y;rt", ":q", "/bin/bash", "/usr/bin/env bash", "gcc -Wall"
    };
    const int len = sizeof(str) / sizeof(char**);
    printf("Str size = %d\n", len);
    printf("Src array:\n");
    for(int i=0;i<len;i++) {
        printf("%d) %s (size: %ld)\n", i, str[i], strlen(str[i]));
    }
    printf("\n\n");
    bubblesort(str, len, sizeof(char*), compare_string);
    //sort_t(str, len, sizeof(char*), compare_string);
    printf("Order of sorted array:\n");
    for(int i=0;i<len;i++) {
        printf("%d) %s (size: %ld)\n", i, str[i], strlen(str[i]));
    }
    printf("\n\n");
}
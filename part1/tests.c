#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

//for random array
#define n 100
#define MIN -500
#define MAX 1000

int *array;

void test_int_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))) {
    int* arr;
    
    srand(time(NULL));
    arr = calloc(n, sizeof(int));
    printf("src array:\n");
    for(int i=0;i<n;i++) {
        arr[i] = rand() % MAX + (MIN);
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    sort(arr, n, sizeof(int), compare_int);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

float timedifference_msec(struct timeval t0, struct timeval t1) {
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void speed_test_int(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))) {
    struct timeval t[4];
    gettimeofday(&t[0], 0);
    const unsigned long max = 100000;
    const int l=-100, r=100;
    array = calloc(max, sizeof(int));
    gettimeofday(&t[1], 0);
    for(unsigned long i=0; i<max;i++) {
        array[i] = rand() % r + l;
    }
    
    gettimeofday(&t[2], 0);
    sort(array, max, sizeof(int), compare_int);
    gettimeofday(&t[3], 0);
    printf("Time make array: %g ms\n",timedifference_msec(t[0], t[1]));
    printf("Time random: %g ms\n", timedifference_msec(t[1], t[2]));
    printf("Program sorted in %g ms.\n", timedifference_msec(t[2], t[3]));
    free(array);
}

void test_float_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))) {
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
    sort(arr, n, sizeof(float), compare_float);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%g ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_char_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))) {
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
    sort(arr, n, sizeof(char), compare_char);
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_string(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))) {
    const char *str[] = {
        "a", "vbudsbv", "ab", "fkbnfjwenvoidhrfio ofierhio irejogvierj ioerjghgiush459830 ghiwuh", "abc",
        "asdfghjkjlkl", "fmnaijbnigtoufwe ibgibgio", "nguirtdhe iuhuihiurthg hiurtohg bigwsoig iuguierwso hg",
        "", "qwerty", "zxc", "qwe", "bndoj hjytiorn y;rt", ":q", "/bin/bash", "/usr/bin/env bash", "gcc -Wall",
        "132", "gie5314543", "xdsl.shgpi.edu.ru", "fserwe5476876 wer", "asdasd", "asdsa", "erttrey", "tertyeye"
    };
    const int len = sizeof(str) / sizeof(char**);
    printf("Str size = %d\n", len);
    printf("Src array:\n");
    for(int i=0;i<len;i++) {
        printf("%d) %s (size: %ld)\n", i, str[i], strlen(str[i]));
    }
    printf("\n\n");
    sort(str, len, sizeof(char*), compare_string);
    //sort(str, len, sizeof(char*), cmpstringp);
    printf("Order of sorted array:\n");
    for(int i=0;i<len;i++) {
        printf("%d) %s (size: %ld)\n", i, str[i], strlen(str[i]));
    }
    printf("\n\n");
}

void print_size(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    printf("size *base = %ld\n", sizeof(base));
    printf("nmemb = %ld | size = %ld\n", nmemb, sizeof(nmemb));
    printf("size = %ld\n", size);
    for(int i=0; i<nmemb-1;i++) {
        printf("size base+%d*size = %ld | = %d\n", i, sizeof(base+i*size), *(int*)(base+i*size));
        printf("size base+(%d+1)*size = %ld | = %d\n", i, sizeof(base+(i+1)*size), *(int*)(base+(i+1)*size));
        printf("compare: %d\n", compare(base+i*size, base+(i+1)*size));
    }
}

void test_print_size() {
    int* arr;
    
    srand(time(NULL));
    arr = calloc(10, sizeof(int));
    for(int i=0;i<10;i++) {
        arr[i] = rand() % MAX + (MIN);
        
    }
    printf("\n\n");
    print_size(arr, 10, sizeof(int), compare_int);
    printf("\n");
    free(arr);
}
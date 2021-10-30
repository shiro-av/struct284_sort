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
    printf("Order of sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
}
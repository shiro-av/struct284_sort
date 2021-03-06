#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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

int cmpstringp(const void *p1, const void *p2)
{
     /* The actual arguments to this function are "pointers to
        pointers to char", but strcmp(3) arguments are "pointers
        to char", hence the following cast plus dereference */

    return strcmp(*(const char **) p1, *(const char **) p2);
}
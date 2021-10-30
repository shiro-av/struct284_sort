#ifndef _sort_h
#define _sort_h

#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b);
int compare_float(const void *a, const void *b);

void bubblesort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));
void test_int_rnd();
void test_float_rnd();

#endif
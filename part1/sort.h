#ifndef _sort_h
#define _sort_h

#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b);
int compare_float(const void *a, const void *b);
int compare_char(const void *a, const void *b);
int compare_string(const void *a, const void *b);

void bubblesort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));
void insertsort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

void test_int_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)));
void test_float_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)));
void test_char_rnd(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)));
void test_string(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)));
void speed_test_int(void(*sort)(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)));

#endif
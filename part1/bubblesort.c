#include "sort.h"


void bubblesort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    char *tmp;
    #define _a base+i*size
    #define _b base+(i+1)*size
    for(int u = 0; u < (nmemb - 1); u++) {
        for(int i=0; i<(nmemb-1);i++) {
            for(int j=(nmemb-1); j>i;j--) {
                if(compare(base+i*size, base+(i+1)*size)==1) {
                    tmp = calloc(sizeof(_a), sizeof(char));
                    memcpy(tmp, _a, size);
                    memcpy(_a, _b, size);
                    memcpy(_b, tmp, size);
                    free(tmp);
                }
            }
        }
    }
}
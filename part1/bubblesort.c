#include "sort.h"

void bubblesort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    char *tmp;
    #define _a base+k*size
    #define _b base+(k+1)*size
    int chg=0;
    for(int i=nmemb-2;i>0;i--) {
        chg=0;
        for(int k=0;k<=i;k++) {
            if(compare(_a, _b)==1) {
                chg=1;
                tmp = calloc(sizeof(_a), sizeof(char));
                memcpy(tmp, _a, size);
                memcpy(_a, _b, size);
                memcpy(_b, tmp, size);
                free(tmp);
            }
        }
        if(chg==0) break;
    }
}


#include "sort.h"
#define _a base+k*size
#define _b base+(k+1)*size

void bubblesort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    char *tmp;
    tmp = calloc(size, sizeof(char));
    int chg=0;
    for(int i=nmemb-2;i>0;i--) {
        chg=0;
        for(int k=0;k<=i;k++) {
            if(compare(_a, _b)>=1) {
                chg=1;
                memcpy(tmp, _a, size);
                memcpy(_a, _b, size);
                memcpy(_b, tmp, size);
            }
        }
        if(chg==0) break;
    }
    free(tmp);
}


#include "sort.h"
#define _a base+j*size
#define _b base+(j+1)*size

void insertsort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    char *tmp, *sw;
    int cnt=0, j=0;
    for(int u=0;u<nmemb-1;u++)
    for(int i=1; i<nmemb;i++) {
        j=i;
        tmp = calloc(sizeof(_a), sizeof(char));
        memcpy(tmp, _a, size);
        while((j>0) && (compare(base+(j-1)*size, _a)==1)) j--;
        memcpy(tmp, _a, size);
        memcpy(_a, _b, size);
        memcpy(_b, tmp, size);
        memcpy(tmp, _a, size);
        cnt++;
        
    }
}
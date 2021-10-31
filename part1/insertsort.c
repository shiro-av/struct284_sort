#include "sort.h"


void insertsort(void *base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
    int j=0, k=0;
    unsigned char *tmp;
    tmp = calloc(size, sizeof(char));
    for(int i=1;i<=nmemb-1;i++) {
        k=i; j=i;
        memcpy(tmp, base+k*size, size);
        while((k>0) && (compare(base+i*size, base+(k-1)*size)==-1)) {
            k--;
        }
        while(j-1>=k) {
            memcpy(base+j*size, base+(j-1)*size, size);
            j--;
        }
        memcpy(base+k*size, tmp, size);
    }
}

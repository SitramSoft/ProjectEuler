#include <stdio.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

int main(){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

    int i, j, k;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

    for (i = 2; i < 1000; i++){
       for (j = i; j < (1000-i); j++){
           for (k = j; k < (1000-j); k++){
               if ((i*i + j*j == k*k) && (i + j + k == 1000)){
                   printf("%d %d %d\n", i, j, k);
				   printf("Solution = %d", i*j*k);
                   break;
               }
           }
       }
    }

#ifdef TIME_MEASUREMENT	
    /* End code measurement */

    clock_gettime(CLOCK_MONOTONIC, &end);
	delta_s = end.tv_sec - start.tv_sec;
	delta_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
	delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    printf("\n\nExecution time:\n%lld s\n%lld ms\n%lld us\n\n", delta_s, delta_ms, delta_us);
#endif

    return 0;
}
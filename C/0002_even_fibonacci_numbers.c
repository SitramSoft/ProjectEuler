#include <stdio.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

#define MAX_VALUE 4000000u

int main(void){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

   int first = 1, second = 2, sum = 0;
   int tmp;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

   while ((first <= MAX_VALUE) && (second <= MAX_VALUE)) {
      if ((second % 2) == 0) {
         sum = sum + second;
      }
      tmp = first + second;
      first = second;
      second = tmp;
   }

   printf("Sum of even Fibonacci numbers below 4 million is %d\n", sum);

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

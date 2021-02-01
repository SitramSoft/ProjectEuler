#include <stdio.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

int check_if_divisible(int a){
  int is_divisible = 1;

  if ((a % 20 != 0) || 
      (a % 19 != 0) ||
      (a % 18 != 0) ||
      (a % 17 != 0) ||
      (a % 16 != 0) ||
      (a % 15 != 0) ||
      (a % 14 != 0) ||
      (a % 13 != 0) ||
      (a % 12 != 0) ||
      (a % 11 != 0)) {
        is_divisible = 0;
   }

   return is_divisible;
}

int main(void) {
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

   int i = 1*2*3*5*7*10*11*13*17*19;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

   while(check_if_divisible(i) == 0){
      i = i+10;
   }

   printf("Number found: %d\n", i);

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

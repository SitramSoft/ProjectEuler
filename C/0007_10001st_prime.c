#include <stdio.h>
#include <math.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

char is_prime(int number);

char is_prime(int number){
   int i=2;
   char prime = 1;

   while (i<=(int)sqrt(number)){
      if ((number % i) == 0){
         prime = 0;
         i = number;
      }
      else
      {
         i++;
      }
   }

   return prime;
}

int main() {
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

   int prime_nr = 6;
   int i = 14;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

   while (prime_nr != 10001){
      if (is_prime(i)){
         prime_nr++;
      }

      i++;
   }

   printf("The 10001st prime number is %d\n", i-1);

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

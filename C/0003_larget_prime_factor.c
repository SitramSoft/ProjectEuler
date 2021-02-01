#include <stdio.h>
#include <math.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

#define NUMBER 600851475143u

int main (void){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

   unsigned long int contor1, contor2, start;
   int flag, found_prime = 0;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

   start = (unsigned long)sqrt(NUMBER);

   for (contor1 = start; contor1 > 1 && found_prime == 0; contor1--){
      //Is this number a divisor?
      if (NUMBER % contor1 == 0){
         flag = 0;
         //Divisor found, check if it's prime
         for (contor2 = 2; contor2 < contor1/2; contor2++){
            if (contor1 % contor2 == 0) {
               flag = 1;
               break;
            }
         }

         if (flag == 0) {
            printf("Found largest  prime divisor: %lu\n", contor1);
            found_prime = 1;
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

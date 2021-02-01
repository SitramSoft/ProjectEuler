#include <stdio.h>
#include <time.h>
#include <math.h>
#include "config.h"

#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

char isPrime(int number);

char isPrime(int number){
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

int main(){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

    int i, notPrime;
    long int sumOfPrimes = 2+3+5+7;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

    /* Insert code below for measurement*/
	
	for (i = 10; i<2000000; i++){
        notPrime = 0;

		if ((i%2==0) || (i%3==0) || (i%5==0) || (i%7==0)) {
            notPrime = 1;
        }

        if (notPrime == 0){
            if (isPrime(i)){
                sumOfPrimes = sumOfPrimes + i;
                }
        }
	}

    printf("Sum of prime numbers below two million = %ld\n", sumOfPrimes);
	
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

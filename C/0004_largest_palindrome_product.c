#include <stdio.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif


int check_palindrom(int a){
   int i = 0, n = 0, found = 1;
   int digits[10];

   //Save the digits of a into an array
   while (a != 0) {
      digits[i] = a % 10;
      a = a / 10;
      i++;
   }

   n = i;

  for (i = 0; i<n/2 && found == 1; i++){
     if (digits[i] != digits[n-i-1]){
        found = 0;
     }
  }

  return found;
}

int main(void){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

   int i,j, max_palindrom = 0;

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

   //Go over all unique numbers made by the product of 3 digits numbers
   for (i = 100; i<999; i++){
      for (j = i; j<999; j++){
         if (check_palindrom(i*j) == 1){
            if (max_palindrom < i*j){
               max_palindrom = i*j;
            }
         }
      }
   }

   printf("Largest palindrom number found is %d\n", max_palindrom);

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

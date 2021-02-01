#include <stdio.h>
#include <math.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

//101us for number 10000
int count_divisors_no_optimizations(unsigned long int n){
    unsigned long int i = 0;
    int count = 0;

    for (i=1; i<=n; i++){
        if  (0 == n%i) {
            count++;
        }
    }

    return count;
}

//21us for number 10000
//looks to be about 5 times faster
int count_divisors(unsigned long int n){
    unsigned long int i = 0;
    int count = 0;

    for (i=1; i<=sqrt(n); i++){
        if  (0 == n%i) {
            // If divisors_count are equal, count only one
            if (n/i == i){
                count++;
            }
            else {
                count+=2;
            }
        }
    }

    return count;
}

int main(){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif
    int i = 0;
    int divisors_count = 0;
    unsigned long int sum = 0;
#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif

    i = 1;
    while(divisors_count < 500){
        sum = sum + i;
        divisors_count = 0;
        i++;
        divisors_count = count_divisors(sum);
    }
    
    printf("First triangle number to have over five hundred divisors is %lu\n", sum);

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

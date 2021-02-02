#include <stdio.h>
#include "config.h"
#ifdef TIME_MEASUREMENT
#include <time.h>
#endif

#define MAX_VALUE 1000000u

int main(){
#ifdef TIME_MEASUREMENT
    struct timespec start, end;
	long long delta_ms, delta_s, delta_us;
#endif

    int n = 1;
    unsigned long int rest, number = 0;
    int iterations, max_iterations = 0;
    unsigned long int map[MAX_VALUE+1] = {0};

#ifdef TIME_MEASUREMENT	
	clock_gettime(CLOCK_MONOTONIC, &start);
    /* Insert code below for measurement*/
#endif
//n → n/2 (n is even)
//n → 3n + 1 (n is odd)

    while (n<MAX_VALUE){
        n=n+1;
        rest = n;
        iterations = 0;
        while (rest > 1){
            if ((rest % 2) == 0){
                rest = rest/2;
            }
            else
            {
                rest = (3 * rest) + 1;
            }
            iterations++;
            
            if (rest < (MAX_VALUE)){
                if (map[rest] != 0){
                    iterations = map[rest] + iterations;
                    rest = 1;
                }
            }
        }

        map[n] = iterations;

        if (iterations >= max_iterations){
            max_iterations = iterations;
            number = n;
        }
    }

    printf("n=%lu -> Chain is %d iterations long.\n", number, max_iterations+1);

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

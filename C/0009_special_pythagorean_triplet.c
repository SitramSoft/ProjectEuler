#include <stdio.h>
#include <time.h>

int main(){
    clock_t begin = clock();

    /* Insert code below for measurement*/
    int i, j, k;

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
    /* End code measurement */

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nExecution time: %g", time_spent);

    return 0;
}
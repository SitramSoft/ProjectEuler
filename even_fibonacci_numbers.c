#include <stdio.h>

#define MAX_VALUE 4000000u

int main(void){
   int first = 1, second = 2, sum = 0;
   int tmp;

   while ((first <= MAX_VALUE) && (second <= MAX_VALUE)) {
      if ((second % 2) == 0) {
         sum = sum + second;
      }
      tmp = first + second;
      first = second;
      second = tmp;
   }

   printf("Sum of even Fibonacci numbers below 4 million is %d\n", sum);

   return 0;
}

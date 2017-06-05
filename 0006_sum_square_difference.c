#include <stdio.h>

int main(){
   int i;
   int sum1 = 0;
   int sum2 = 0;
   
   for (i = 1; i<=100; i++){
      sum1 = sum1 + i;
      sum2 = sum2 + i*i;
   }

   printf("%d - %d = %d\n", sum1*sum1, sum2, (sum1*sum1) - sum2);
   return 0;
}


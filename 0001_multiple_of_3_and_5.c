#include <stdio.h>

int main() {
   int contor;
   int count = 0;

   for (contor = 0; contor < 1000; contor++) {
      if (((contor % 3) == 0) || ((contor % 5) == 0)) {
         count = count + contor;
      }
   }

   printf("Sum of all the multiples of 3 or 5 below 1000 is %d\n", count);

   return 0;
}

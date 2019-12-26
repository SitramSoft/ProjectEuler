#include <stdio.h>
#include <math.h>

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
   int prime_nr = 6;
   int i = 14;

   while (prime_nr != 10001){
      if (is_prime(i)){
         prime_nr++;
      }

      i++;
   }

   printf("The 10001st prime number is %d\n", i-1);
   return 0;
}

#include <stdio.h>
#include <math.h>

#define NUMBER 600851475143u

int main (void){
   unsigned long int contor1, contor2, start;
   int flag, found_prime = 0;

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

   return 0;
}

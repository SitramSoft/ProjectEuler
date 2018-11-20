#include <stdio.h>
#include <time.h>
#include <math.h>

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
    clock_t begin = clock();
    int i, notPrime;
    long int sumOfPrimes = 2+3+5+7;

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

    printf("Sum of prime numbers below two million = %ld", sumOfPrimes);
	
    /* End code measurement */

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nExecution time: %g", time_spent);

    return 0;
}

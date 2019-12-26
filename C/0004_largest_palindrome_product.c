#include <stdio.h>

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
   int i,j, max_palindrom = 0;

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

   return 0;
}

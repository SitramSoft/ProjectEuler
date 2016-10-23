#include <stdio.h>

int check_palindrom(int a){
   int i;

   for (i=0; i<
}

int main(void){
   int i,j, max_palindrom = 0;

   for (i = 100; i<999; i++){
      for (j = i; j<999; j++){
         if (check_palindrome(i*j) == 0){
            printf("Found palindrom: %d/n", i*j);
            if (max_palindrom < i*j){
               max_palindrom = i*j;
            }
      }
   }
   return 0;
}

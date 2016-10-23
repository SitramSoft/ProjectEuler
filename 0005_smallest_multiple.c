#include <stdio.h>

int check_if_divisible(int a){
  int is_divisible = 1;

  if ((a % 20 != 0) || 
      (a % 19 != 0) ||
      (a % 18 != 0) ||
      (a % 17 != 0) ||
      (a % 16 != 0) ||
      (a % 15 != 0) ||
      (a % 14 != 0) ||
      (a % 13 != 0) ||
      (a % 12 != 0) ||
      (a % 11 != 0)) {
        is_divisible = 0;
   }

   return is_divisible;
}

int main(void) {
   int i = 20;

   while(check_if_divisible(i) == 0){
      i++;
   }

   printf("Number found: %d\n", i);
   return 0;
}

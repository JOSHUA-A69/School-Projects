#include <stdio.h>

int main(){
	int num,positive_count = 0, negative_count = 0;
	 printf("Enter 5 numbers\n");
      while (1) {
        scanf("%d", &num)
        
		;
        if (num == 0) {
          break;
        }
        if (num > 0) {
          positive_count++;
        } else if (num < 0) {
          negative_count++;
        }
      }
       printf("\nNumber of positive numbers entered: %d\n", positive_count);
       printf("Number of negative numbers entered: %d\n", negative_count);
    }
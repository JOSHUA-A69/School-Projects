#include <stdio.h>

int main()
{
	int num1, num2, num3;

	printf("Enter 3 numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1>= num2 && num1 >= num3){
	
		printf("Maximum value of the 3 numbers:%d", num1);
   }
	else if (num2>= num1&& num2 >= num3){
		printf("Maximum value of the 3 numbers:%d", num2);
    }
	else{
		printf("Maximum value of the 3 numbers:%d", num3);
  }
	return 0;
}

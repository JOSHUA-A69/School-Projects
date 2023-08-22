#include <stdio.h>

void input(int *num1, int *num2, int *num3){
	printf("Input 3 Numbers\n");
	scanf("%d",num1);
	scanf("%d",num2);
	scanf("%d",num3);
}

void reverse(int *num1, int *num2, int *num3){
	 int temp;
	 temp = *num1;
	 *num1 = *num3;
	 *num3 = temp;
	 
   printf("The reverse of %d %d %d is %d %d %d",*num3, *num2, *num1,*num1, *num2, *num3);

}

int main(){
	
	int num1,num2,num3;
	
	input(&num1,&num2,&num3);
	reverse(&num1,&num2,&num3);
	
	return 0;
}
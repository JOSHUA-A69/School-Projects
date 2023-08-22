#include <stdio.h>

void input(int *num){
	printf("Input Integer:");
	scanf("%d",num);
}
void reverse(int *num){
	
	int reversed = 0;
	int original = *num
	printf("The reverse of %d is %d",*num,reversed);
}

int main(){
	
	int num;
	
	input(&num);
	reverse(&num);
}
#include <stdio.h>

float compBmi(float meters, float kg){
	float bmi= kg /(meters*meters);
	return bmi; 
}
int main(){
	float meters,kg;
	
	while(1){
	printf("\n\nEnter height in meters:");
	scanf("%f",&meters);
	printf("\n\nEnter weight in kg:");
	scanf("%f",&kg);
	if(meters==0 && kg==0){
		break;
	}
	
	float bmi=compBmi(meters,kg);
	printf("\n\nYou are %.1f\n\n",bmi);
    
	
	if(bmi<18.5){
		printf("You are underweight",bmi);
	}
	else if(bmi>=18.5 && bmi<25 ){
		printf("You are normalweight",bmi);
	}
	else if(bmi>=25 && bmi<30){
		printf("You are Overweight",bmi);
	}
	else{
		printf("You are Obese",bmi);
	}
}
}





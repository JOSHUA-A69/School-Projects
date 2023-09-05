/*C program that accepts 10 letters.  These letters should be either ‘a’, ‘b’, or ‘c’ only. It should store these into an array. 
 The program counts the number of ‘a’, ‘b’, or ‘c’. Display these counts.*/
 
 
 #include <stdio.h>

#define letters 10

void acceptletters(char letters[letters]){
	int ctr;
	
	printf("Input 10 letterss: ");
	for(ctr = 0; ctr < letters; ctr++){
		printf("\n#%c: ", ctr+1);
		scanf("%c", &letters[ctr]);
	}
}

void displayNum(int num[size]){
	int ctr;
	
	printf("\nContents of the array: ");
	for(ctr = 0; ctr < size; ctr++){
		printf("\n#%d: %d", ctr+1, num[ctr]);
	}
}

void countEvenOdd(int num[size]){
	int ctr, odd = 0, even = 0;
	
	for(ctr = 0; ctr < size; ctr++){
		if(num[ctr] % 2 == 0)
		  even++;
		else
		  odd++;  
	}
	displayNum(num);
	printf("\nOdd = %d", odd);
	printf("\nEven = %d", even);
}

main(){
	char letters[letters];
	
	acceptletters(letters);
	displayNum(num);
	countEvenOdd(num);
}

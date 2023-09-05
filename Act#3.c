/*C program that accepts 10 letters.  These letters should be either ‘a’, ‘b’, or ‘c’ only. It should store these into an array. 
 The program counts the number of ‘a’, ‘b’, or ‘c’. Display these counts.*/
 #include <stdio.h>
 #define letters 10

void acceptletters(char lett[letters]){
	int ctr;
	
	printf("Input 10 letterss: ");
	for(ctr = 0; ctr < letters; ctr++){
		printf("\n#%c: ", ctr+1);
		scanf("%c", &lett[ctr]);
	}
}

void countletters(char lett[letters]){
	int ctr, 'a'= 0, 'b' = 0, 'c' = 0;
	
	for(ctr = 0; ctr < letters; ctr++){
		if(num[ctr] % 2 == 0)
		  'a'++;
		if else
		  'b'++;  
	    else
		'c'++;
	}
	displaynumberofabc(lett);
	printf("\nNumber of A = %c", 'a');
	printf("\nNumber of B = %c", 'b');
	printf("\nNumber of B = %c", 'c');
}

int main(){
	
	
}

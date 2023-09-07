#include <stdio.h>


void acceptletters(char lett[], int letters){
	int ctr;
	printf("Input %d Letters:",letters);
	for(ctr = 0; ctr < letters; ctr++){
		printf("\n#%d:", ctr + 1);
		scanf(" %c",&lett[ctr]);
	}
}

void countletters(char lett[], int letters){
	int ctr, a = 0, b = 0, c = 0;

	for (ctr = 0; ctr < letters; ctr++){
		char currentChar = lett[ctr];
		currentChar = toupper(currentChar);
		
		if(lett[ctr] == 'A'){
			a++;
		}
	else if (lett[ctr] == 'B'){
		b++;
	}
   else if (lett[ctr] == 'C'){
	c++;
   }
	}
	 printf("\nNumber of A = %d", a);
     printf("\nNumber of B = %d", b);
     printf("\nNumber of C = %d", c);

}

int main(){
	char text[] = "aAbBcC";
	int letters = 10;
	char lett[letters];

	acceptletters(lett,letters);
	countletters(lett,letters);
	return 0;
}

   

   

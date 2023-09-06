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
	int ctr, lower_a = 0, lower_b = 0, lower_c = 0, upper_a = 0, upper_b = 0, upper_c = 0;

	for (ctr = 0; ctr < letters; ctr++){
		char currentChar = lett[ctr];
		
		
	if(currentChar == 'a'){
	 lower_a++;
		}
	else if (currentChar == 'A'){
	  upper_a++;
	}
    else if (currentChar == 'b'){
	  lower_b++;
   }
    else if (currentChar == 'B'){
   	 upper_b++;
   }
    else if (currentChar == 'c'){
   	 lower_c++;
   }
    else if (currentChar == 'C'){
   	 upper_c++;
   }
	}
    printf("\nNumber of lowercase A = %d", lower_a);
    printf("\nNumber of uppercase A = %d", upper_a);
    printf("\nNumber of lowercase B = %d", lower_b);
    printf("\nNumber of uppercase B = %d", upper_b);
    printf("\nNumber of lowercase C = %d", lower_c);
    printf("\nNumber of uppercase C = %d", upper_c);

}

int main(){
	int letters = 10;
	char lett[letters];

	acceptletters(lett,letters);
	countletters(lett,letters);
	return 0;
}

   

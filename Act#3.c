#include <stdio.h>

void acceptletters(char lett[], int letters){
	int ctr;
	printf("Input %d Letters:",letters);
	for(ctr = 0; ctr < letters; ctr++){
		printf("\n#%d:", ctr + 1);
		scanf(" %c",&lett[ctr]);
		if(lett[ctr] != 'A' && lett[ctr] !='a' && lett[ctr] != 'B' && lett[ctr] != 'b' && lett[ctr] != 'C' && lett[ctr] != 'c') {
		printf("invalid input!");
		break;
   }
 }
}
void countletters(char lett[], int letters){
	int ctr, a = 0, b = 0, c = 0;

	for (ctr = 0; ctr < letters; ctr++){
	
		
	if(lett[ctr] == 'A' || lett[ctr] == 'a'){
	a++;
		}
	else if (lett[ctr] == 'B' || lett[ctr] == 'b'){
	b++;
	}
   else if (lett[ctr] == 'C' || lett[ctr] == 'c'){
	c++;
   }
 }	 printf("\nNumber of A = %d", a);
     printf("\nNumber of B = %d", b);
     printf("\nNumber of C = %d", c);

}

int main(){
	int letters = 10;
	char lett[letters];

	acceptletters(lett,letters);
	countletters(lett,letters);
	return 0;
}

   

   

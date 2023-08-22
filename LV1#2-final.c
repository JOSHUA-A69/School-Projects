#include <stdio.h>
#include <string.h>

int main(){
 char input[3];

  printf("Input 3 Characters:");
  scanf("%s",&input);
  
  char originalInput[4];
  strcpy(originalInput,input);
  strrev(input);
  
  printf("%s in reversed is %s",originalInput,input);
}
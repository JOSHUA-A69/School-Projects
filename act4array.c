#include <stdio.h>
#include <stdlib.h>

#define cSize 4
#define rSize 3

void acceptScores(int scores[rSize][cSize]){
	int row, col;
	
	printf("Enter the scores of 3 students in the 4 quizzes:\n");
	
	for(row = 0; row < rSize; row++){
		printf("\nStudent %d:\n\n", row+1);
		for(col = 0; col < cSize; col++){
			printf("Quiz %d:\t", col+1);
			scanf("%d", &scores[row][col]);
			if(scores[row][col] < 0){
				printf("Invalid input...");
				fflush(stdin);
				exit(0);
			}
		}
	}
	
}

void displayAllScores(int scores[rSize][cSize]){
	int row, col;
	
	printf("\n\nScores of all students:\n");
	for(row = 0; row < rSize; row++){
		printf("\nStudent %d:\n\n", row+1);
		for(col = 0; col < cSize; col++){
			printf("Quiz %d: %d\n", col+1, scores[row][col]);
			
		}
	}
	printf("\n");
}

void displayStudentScore(int scores[rSize][cSize], int student){
	int col;
	printf("\nWhich student would you want the scores to be displayed (1, 2, or 3): ");
	scanf("%d", &student);
	printf("\nScores of student no. %d\n", student);
	for(col = 0; col < cSize; col++){
		printf("Quiz %d:\t%d\n", col+1, scores[student - 1][col]);
	}
}


void computeStudentAve(int scores[rSize][cSize], int student){
	int col;
	float  sum = 0;
	
	printf("\nWhich student would you want the average scores to be displayed (1, 2, or 3): \n");
	scanf("%d", &student);
	
	
	for(col = 0; col < cSize; col++){
		printf("Quiz %d:\t%d\n", col+1, scores[student - 1][col]);
		sum += scores[student-1][col];
		}printf("\n\nAverage Score of student # %d: %.2f", student, sum / 4);
	
}

void showQuizStats(int scores[rSize][cSize], int quizNo){
	int row, col, max = 0, min = 0;
	float sum = 0, ave;
	
	printf("Input the quiz number: ");
	scanf("%d", &quizNo);
	printf("\n\nQuiz statistics:\n");
	
	
	for(row = 0; row < rSize; row++){
		sum += scores[row][quizNo - 1];
		ave = sum / 3;			
	}printf("\n\nThe average score of quiz no. %d: %.2f", quizNo, ave);
	

	for(row = 0; row < rSize; row++){
		for(col = 0; col < cSize; col++){
		if(max < scores[row][quizNo - 1])
		max = scores[row][quizNo - 1];
		}	
	}printf("\n\nHighest score: %d", max);
	
	
	min = scores[0][0];
	for(row = 0; row < rSize; row++){
		for(col = 0; col < cSize; col++){
		if(min > scores[row][quizNo - 1])
		min = scores[row][quizNo - 1];
		}	
	}printf("\n\nLowest score: %d", min);
		
}

    

int main(){
	int scores[rSize][cSize], student, option, ans = 0, quizNo;
	
	
	acceptScores(scores);
	system("CLS");
	
	while(ans == 0 ){
	printf("\n\nChoose your option:\n1. Display all scores\n2. Display the scores of a specific student\n3. Display the average score of a specific student\n4. Display quiz statistics (Find the lowest score, highest score, average score)");
	printf("\n\nEnter option: ");
	scanf("%d", &option);
	system("CLS");
	
	switch(option){
		case 1: displayAllScores(scores);
				fflush(stdin);break;
		case 2: displayStudentScore(scores, student);
				fflush(stdin);break;		
		case 3: computeStudentAve(scores, student);
				fflush(stdin);break;
		case 4: showQuizStats(scores, quizNo);
				fflush(stdin);break;
		default: printf("\n\nWrong option. [1,2,3 or 4 only]");		
				
	}
		printf("\n\nDo you want to continue using this program? [0 - Yes/10 - No]>> ");
		scanf("%d", &ans);
		system("CLS");
		if (ans != 0){
			printf("\n\nWrong option. [0- Yes or 10 - No only]");
			printf("\n\n\nDo you want to continue using this program? [0 - Yes/10 - No]>> ");
			scanf("%d", &ans);	
		}
		if (ans == 10){
			printf("\n\nThank you for using our program...");
			printf("\n\nEnd of the program");
			exit(0);
		}		
	}	
}


#include <stdio.h>


void acceptScores(float scores[3][4]) {
    printf("Enter scores for 3 students and 4 quizzes:\n");
    
    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        
        for (int j = 0; j < 4; j++) {
            printf("  Quiz %d: ", j + 1);
            scanf("%f", &scores[i][j]);
        }
    }
}

void displayAllScore(float scores[3][4]) {
    printf("\nStudent scores\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        
        for (int j = 0; j < 4; j++) {
            printf("  Quiz %d %.2f\n", j + 1, scores[i][j]);
        }
    }
}

void computeStudentAve(float scores[3][4]) {
    printf("\nStudent averages\n");

    for (int i = 0; i < 3; i++) {
       float sum = 0.0;
        for (int j = 0; j < 4; j++) {
           sum += scores[i][j];   
        }
        float average = sum / 4.0;
        printf("Student %d Average: %.2f\n", i + 1, average);
    }
}


int main(){
float scores[3][4];

    acceptScores(scores);
    displayAllScore(scores);
    computeStudentAve(scores);
}
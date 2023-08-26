#include <stdio.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;  // Stack is empty
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("%d\n", pop());  // Outputs 30
    printf("%d\n", pop());  // Outputs 20
    
    return 0;
}

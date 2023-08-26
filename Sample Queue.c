#include <stdio.h>

#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int itemCount = 0;

void enqueue(int item) {
    if (itemCount < MAX_SIZE) {
        queue[++rear] = item;
        itemCount++;
    }
}

int dequeue() {
    if (itemCount > 0) {
        int item = queue[front++];
        itemCount--;
        return item;
    }
    return -1;  // Queue is empty
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("%d\n", dequeue());  // Outputs 10
    printf("%d\n", dequeue());  // Outputs 20
    
    return 0;
}

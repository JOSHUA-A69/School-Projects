#include <stdio.h>
#define SIZE 10

struct KeyValue {
    int key;
    int value;
};

struct KeyValue hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(int key) {
    int index = hashFunction(key);
    return hashTable[index].value;
}

int main() {
    insert(5, 100);
    insert(15, 200);
    
    printf("%d\n", search(5));    // Outputs 100
    printf("%d\n", search(15));   // Outputs 200
    
    return 0;
}

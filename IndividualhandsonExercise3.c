#include <stdio.h>

#define size 8

void bubbleSortAscending(int arr[]) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortDescending(int arr[]) {
    int i, j, max_index, temp;
    for (i = 0; i < size - 1; i++) {
        max_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

void insertionSort(int arr[], int ascending) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    int ages[size] = {32, 25, 19, 45, 28, 36, 22, 30};
    int choice = -1;

    do {
        printf("\nMenu:\n");
        printf("1. Display all elements\n");
        printf("2. Bubble sort elements in ascending order\n");
        printf("3. Selection sort elements in descending order\n");
        printf("4. Insertion sort elements in ascending or descending order\n");
        printf("0. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("All Elements: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", ages[i]);
                }
                printf("\n");
                break;

            case 2:
                bubbleSortAscending(ages);
                printf("Sorted Ages in Ascending order:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", ages[i]);
                }
                printf("\n");
                break;

            case 3:
                selectionSortDescending(ages);
                printf("Sorted Ages in Descending order:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", ages[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Enter 0 for descending or 1 for ascending: ");
                int sortChoice;
                scanf("%d", &sortChoice);
                insertionSort(ages, sortChoice);
                if (sortChoice == 0) {
                    printf("Sorted Ages in Descending Order using Insertion Sort:\n");
                } else {
                    printf("Sorted Ages in Ascending Order using Insertion Sort:\n");
                }
                for (int i = 0; i < size; i++) {
                    printf("%d ", ages[i]);
                }
                printf("\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}



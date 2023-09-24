#include <stdio.h>

int sentinelSearch(int arr[], int n, int target) {
    int lastElement = arr[n - 1]; // Store the last element
    arr[n - 1] = target; // Set the last element as the sentinel value

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[n - 1] = lastElement; // Restore the original last element

    if (i < n - 1 || target == arr[n - 1]) {
        return i; // Return the index where the target is found
    } else {
        return -1; // Return -1 if the target is not found in the array
    }
}

int main() {
    int arr[] = {2, 4, 7, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = sentinelSearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}

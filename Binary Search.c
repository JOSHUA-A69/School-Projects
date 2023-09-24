#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is equal to the target
        if (arr[mid] == target) {
            return mid; // Target found, return its index
        }

        // If the target is less than the middle element, search the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }

        // If the target is greater than the middle element, search the right half
        else {
            left = mid + 1;
        }
    }

    return -1; // Target not found in the array
}

int main() {
    int arr[] = {1020, 1123, 2011, 2125, 2135, 3212, 3342, 4321, 4434};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4434;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}

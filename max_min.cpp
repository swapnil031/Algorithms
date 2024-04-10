#include <iostream>
#include <climits>

// Function to find maximum and minimum in an array using divide and conquer
void findMaxMin(int arr[], int low, int high, int* max, int* min) {
    if (low == high) {
        *max = *min = arr[low]; // Base case: Only one element in the array
        return;
    }

    if (high == low + 1) {
        // Two elements in the array, compare them to find max and min
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;

    // Divide the array into two halves and recursively find max and min in each half
    findMaxMin(arr, low, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

    // Compare max and min from the two halves
    if (leftMax > rightMax)
        *max = leftMax;
    else
        *max = rightMax;

    if (leftMin < rightMin)
        *min = leftMin;
    else
        *min = rightMin;
}

int main() {
    int arr[] = {4,6 ,1, 2, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    std::cout << "Maximum element: " << max << std::endl;
    std::cout << "Minimum element: " << min << std::endl;

    return 0;
}

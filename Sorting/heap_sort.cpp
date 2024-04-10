#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int end_index = n - 1; end_index > 0; end_index--) {
        // Move current root to end
        swap(arr[0], arr[end_index]);

        // call max heapify on the reduced heap
        heapify(arr,end_index, 0);
    }
}

// Function to print an array
void printArray(const vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    cout << "Original array: \n";
    printArray(arr);
    heapSort(arr);
    cout << "Sorted array: \n";
    printArray(arr);
    return 0;
}

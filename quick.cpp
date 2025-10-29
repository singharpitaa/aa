#include <iostream>
using namespace std;

// Partition function using pivot = arr[low]
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1)
            i++;
        while(arr[j] > pivot && j >= low + 1)
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // place pivot in correct position
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // left part
        quickSort(arr, pi + 1, high); // right part
    }
}

int main() {
    int arr[] = {25, 5, 20, 15, 10, 30};
    int n = 6;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

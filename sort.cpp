#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(float arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}


void bubbleSort(float arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    float salary[] = {45000.5, 32000, 58000.75, 29000, 76000.90, 50000, 61000};
    int n = 7;

  
    selectionSort(salary, n);
    cout << "Salaries after Selection Sort: ";
    for(int i = 0; i < n; i++)
        cout << salary[i] << " ";
    cout << endl;

    
    bubbleSort(salary, n);
    cout << "Salaries after Bubble Sort: ";
    for(int i = 0; i < n; i++)
        cout << salary[i] << " ";
    cout << endl;

    
    cout << "\nTop 5 Highest Salaries: ";
    for(int i = n - 1; i >= n - 5; i--)
        cout << salary[i] << " ";
    cout << endl;

    return 0;
}

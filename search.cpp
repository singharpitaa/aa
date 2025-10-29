#include <iostream>
using namespace std;


bool linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return true;
    }
    return false;
}


bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return true;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int arr[] = {101, 203, 305, 412, 589}; 
    int n = 5;
    int key;

    cout << "Enter Customer ID to Search: ";
    cin >> key;

    if(linearSearch(arr, n, key))
        cout << "Found using Linear Search!" << endl;
    else
        cout << "Not Found using Linear Search!" << endl;

    if(binarySearch(arr, n, key))
        cout << "Found using Binary Search!" << endl;
    else
        cout << "Not Found using Binary Search!" << endl;

    return 0;
}

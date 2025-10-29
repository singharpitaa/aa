#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE] = {-1};

// Hash function
int hashFunc(int key) {
    return key % SIZE;
}

// Insert without replacement
void insertNoReplace(int key) {
    int index = hashFunc(key);
    while (hashTable[index] != -1 && hashTable[index] != -2) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Search
int searchKey(int key) {
    int index = hashFunc(key);
    int start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) return index;
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    return -1;
}

// Delete
void deleteKey(int key) {
    int index = searchKey(key);
    if (index != -1) hashTable[index] = -2;
    else cout << "Key not found\n";
}

// Display
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) cout << i << ": NULL\n";
        else if (hashTable[i] == -2) cout << i << ": DELETED\n";
        else cout << i << ": " << hashTable[i] << endl;
    }
}

int main() {
    insertNoReplace(15);
    insertNoReplace(25);
    insertNoReplace(35);
    insertNoReplace(5);

    display();
    return 0;
}
 


 #include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE] = {-1};

// Hash function
int hashFunc(int key) {
    return key % SIZE;
}

// Insert without replacement
void insertNoReplace(int key) {
    int index = hashFunc(key);
    while (hashTable[index] != -1 && hashTable[index] != -2) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Search
int searchKey(int key) {
    int index = hashFunc(key);
    int start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) return index;
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    return -1;
}

// Delete
void deleteKey(int key) {
    int index = searchKey(key);
    if (index != -1) hashTable[index] = -2;
    else cout << "Key not found\n";
}

// Display
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) cout << i << ": NULL\n";
        else if (hashTable[i] == -2) cout << i << ": DELETED\n";
        else cout << i << ": " << hashTable[i] << endl;
    }
}

int main() {
    insertNoReplace(15);
    insertNoReplace(25);
    insertNoReplace(35);
    insertNoReplace(5);

    display();
    return 0;
}

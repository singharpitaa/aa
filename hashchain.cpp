#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;
list<int> hashTable[SIZE];

int hashFunc(int key) {
    return key % SIZE;
}

void insertKey(int key) {
    hashTable[hashFunc(key)].push_back(key);
    cout << "Inserted " << key << endl;
}

void searchKey(int key) {
    int index = hashFunc(key);
    bool found = false;
    for (int k : hashTable[index]) {
        if (k == key) {
            cout << "Key " << key << " found at index " << index << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Key not found\n";
}

void deleteKey(int key) {
    int index = hashFunc(key);
    bool found = false;
    hashTable[index].remove(key); // removes all occurrences of key
    cout << "Key " << key << " deleted (if existed).\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (int k : hashTable[i])
            cout << k << " ";
        cout << endl;
    }
}

int main() {
    int choice, key;

    while (true) {
        cout << "\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        if (choice != 4) {
            cout << "Enter key: ";
            cin >> key;
        }

        if (choice == 1) insertKey(key);
        else if (choice == 2) searchKey(key);
        else if (choice == 3) deleteKey(key);
        else if (choice == 4) display();
        else cout << "Invalid choice!\n";
    }

    return 0;
}

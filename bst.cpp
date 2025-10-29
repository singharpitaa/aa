#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* n = new Node();
    n->data = x;
    n->left = n->right = nullptr;
    return n;
}

// Insert
Node* insert(Node* root, int x) {
    if (root == nullptr) return createNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

// Search
bool search(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}

// Find min value in right subtree
Node* minValue(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Delete
Node* deleteNode(Node* root, int x) {
    if (!root) return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder Display
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Predefined inputs (feel free to change)
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    cout << "Inserting elements: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
        root = insert(root, values[i]);
    }
    cout << endl;

    cout << "BST Inorder (sorted): ";
    inorder(root);
    cout << endl;

    cout << "Searching 40: ";
    cout << (search(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Deleting 30..." << endl;
    root = deleteNode(root, 30);

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}

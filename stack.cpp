#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undoStack, redoStack;
    string current = "", change;
    int choice = -1;

    while(choice != 0) {
        cout << "\n1.Make Change 2.Undo 3.Redo 4.Show 0.Exit\nChoose: ";
        cin >> choice;

        switch(choice) {
            case 1: // Make Change
                cout << "Enter new text: ";
                cin >> change;         
                undoStack.push(current);
                current += change;     
                while(!redoStack.empty()) redoStack.pop();
                break;

            case 2: // Undo
                if(!undoStack.empty()) {
                    redoStack.push(current);
                    current = undoStack.top();
                    undoStack.pop();
                } else cout << "Nothing to undo!";
                break;

            case 3: // Redo
                if(!redoStack.empty()) {
                    undoStack.push(current);
                    current = redoStack.top();
                    redoStack.pop();
                } else cout << "Nothing to redo!";
                break;

            case 4: // Show Document
                cout << "Document: " << current << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!";
        }
    }

    return 0;
}

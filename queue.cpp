#include <iostream>
#include <queue>
using namespace std;

// Structure for a call
struct Call {
    int customerID;
    int callTime; // in minutes
};

int main() {
    queue<Call> callQueue;
    int choice;
    Call newCall;

    while(true) {
        cout << "\n1.Add Call 2.Answer Call 3.View Queue 4.Check Empty 0.Exit\nChoose: ";
        cin >> choice;

        switch(choice) {
            case 1: // Add Call
                cout << "Enter Customer ID: ";
                cin >> newCall.customerID;
                cout << "Enter Call Time (minutes): ";
                cin >> newCall.callTime;
                callQueue.push(newCall);
                break;

            case 2: // Answer Call
                if(!callQueue.empty()) {
                    cout << "Answering Customer ID: " << callQueue.front().customerID 
                         << ", Call Time: " << callQueue.front().callTime << " mins\n";
                    callQueue.pop();
                } else {
                    cout << "No calls in queue!\n";
                }
                break;

            case 3: // View Queue
                if(callQueue.empty()) {
                    cout << "Queue is empty!\n";
                    break;
                }
                cout << "Calls in Queue:\n";
                {
                    queue<Call> temp = callQueue; // copy to display
                    while(!temp.empty()) {
                        cout << "Customer ID: " << temp.front().customerID 
                             << ", Call Time: " << temp.front().callTime << " mins\n";
                        temp.pop();
                    }
                }
                break;

            case 4: // Check if empty
                if(callQueue.empty())
                    cout << "Queue is empty!\n";
                else
                    cout << "Queue has " << callQueue.size() << " call(s).\n";
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

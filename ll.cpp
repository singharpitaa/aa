#include <iostream>
using namespace std;

// Structure for a student
struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

// Function to add student at end
void addStudent(Student*& head, int roll, string name, float marks) {
    Student* newNode = new Student{roll, name, marks, nullptr};
    if(!head) head = newNode;
    else {
        Student* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}


void display(Student* head) {
    if(!head) { cout << "No records.\n"; return; }
    cout << "Roll\tName\tMarks\n";
    while(head) {
        cout << head->rollNo << "\t" << head->name << "\t" << head->marks << "\n";
        head = head->next;
    }
}


Student* search(Student* head, int roll) {
    while(head) {
        if(head->rollNo == roll) return head;
        head = head->next;
    }
    return nullptr;
}


void deleteStudent(Student*& head, int roll) {
    if(!head) return;
    if(head->rollNo == roll) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Student* temp = head;
    while(temp->next && temp->next->rollNo != roll) temp = temp->next;
    if(temp->next) {
        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}


void sortByMarks(Student* head) {
    for(Student* i=head;i;i=i->next) {
        for(Student* j=i->next;j;j=j->next) {
            if(i->marks > j->marks) swap(i->rollNo, j->rollNo), swap(i->name, j->name), swap(i->marks, j->marks);
        }
    }
}


void updateStudent(Student* head, int roll, float newMarks) {
    Student* s = search(head, roll);
    if(s) s->marks = newMarks;
}

int main() {
    Student* head = nullptr;
    int choice, roll;
    string name;
    float marks;

    while(true) {
        cout << "\n1.Add 2.Delete 3.Update 4.Search 5.Sort 6.Display 0.Exit\nChoose: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Roll No: "; cin >> roll;
                cout << "Name: "; cin >> name;
                cout << "Marks: "; cin >> marks;
                addStudent(head, roll, name, marks);
                break;
            case 2:
                cout << "Roll No to delete: "; cin >> roll;
                deleteStudent(head, roll);
                break;
            case 3:
                cout << "Roll No to update: "; cin >> roll;
                cout << "New Marks: "; cin >> marks;
                updateStudent(head, roll, marks);
                break;
            case 4:
                cout << "Roll No to search: "; cin >> roll;
                {
                    Student* s = search(head, roll);
                    if(s) cout << "Found: " << s->rollNo << " " << s->name << " " << s->marks << "\n";
                    else cout << "Not found.\n";
                }
                break;
            case 5:
                sortByMarks(head);
                cout << "Sorted by marks.\n";
                break;
            case 6:
                display(head);
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int coeff, exp;
    Node* next;
    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

void insert(Node*& head, int c, int e) {
    Node* temp = new Node(c, e);
    if (!head || head->exp < e) {
        temp->next = head;
        head = temp;
    } else {
        Node* curr = head;
        while (curr->next && curr->next->exp > e) curr = curr->next;
        if (curr->exp == e) curr->coeff += c;
        else if (curr->next && curr->next->exp == e) curr->next->coeff += c;
        else {
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}

Node* parsePoly(string s) {
    Node* head = NULL;
    int i = 0;
    while (i < s.size()) {
        int sign = 1;
        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') i++;

        int coeff = 0;
        while (isdigit(s[i])) coeff = coeff * 10 + (s[i++] - '0');
        coeff *= sign;

        if (s[i] == 'x') i++;

        int exp = 0;
        while (i < s.size() && isdigit(s[i])) exp = exp * 10 + (s[i++] - '0');

        insert(head, coeff, exp);
    }
    return head;
}

Node* addPoly(Node* a, Node* b) {
    Node* res = NULL;
    while (a) { insert(res, a->coeff, a->exp); a = a->next; }
    while (b) { insert(res, b->coeff, b->exp); b = b->next; }
    return res;
}

// Polynomial Multiplication
Node* multiplyPoly(Node* a, Node* b) {
    Node* res = NULL;
    for(Node* p = a; p != NULL; p = p->next) {
        for(Node* q = b; q != NULL; q = q->next) {
            int c = p->coeff * q->coeff;
            int e = p->exp + q->exp;
            insert(res, c, e);  // Insert result term
        }
    }
    return res;
}

string polyToStr(Node* head) {
    if (!head) return "0";
    string res = "";
    while (head) {
        if(head->coeff >= 0 && !res.empty()) res += "+";
        res += to_string(head->coeff) + "x" + to_string(head->exp);
        head = head->next;
    }
    return res;
}

int main() {
    string s1 = "5x2+3x1+7x0";
    string s2 = "1x2-6x1+9x0";

    Node* p1 = parsePoly(s1);
    Node* p2 = parsePoly(s2);

    Node* sum = addPoly(p1, p2);
    Node* mul = multiplyPoly(p1, p2);

    cout << "Addition: " << polyToStr(sum) << endl;
    cout << "Multiplication: " << polyToStr(mul) << endl;

    return 0;
}

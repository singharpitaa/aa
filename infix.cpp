#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
 * @brief Helper function to determine the precedence of operators.
 * This is the 'priority()' function mentioned in your second image.
 * Higher number means higher precedence.
 */
int priority(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1; 
}


string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";
    int n = s.length();

    // The loop iterates through the string, as shown in the image
    for (int i = 0; i < n; i++) {

        // 1. Check for operand (A-Z, a-z, 0-9)
        // This is the 'if' block from your first image.
        // (Note: I corrected the typo 'a' <= 'a' to 'a' <= 'z')
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans + s[i];
        }

        // 2. Check for opening parenthesis
        else if (s[i] == '(') {
            st.push(s[i]);
        }

        // 3. Check for closing parenthesis
        else if (s[i] == ')') {
            // Pop from stack and add to 'ans' until '(' is found
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            // Pop the '(' from the stack (this step was implied)
            if (!st.empty()) {
                st.pop();
            }
        }

        
        else {
            
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            
            st.push(s[i]);
        }
    } 

    
    while (!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

int main() {
    // Example usage
    string expression = "a+b*(c^d-e)/(f+g*h)-i";
    
    cout << "Infix Expression: " << expression << endl;
    
    string postfix = infixToPostfix(expression);
    cout << "Postfix Expression: " << postfix << endl;

    // Example 2
    string expression2 = "(A-B/C)*(A/K-L)";
    cout << "\nInfix Expression: " << expression2 << endl;
    cout << "Postfix Expression: " << infixToPostfix(expression2) << endl;

    return 0;
}
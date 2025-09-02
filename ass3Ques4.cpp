#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stackArr[MAX];
int top = -1;

// push into stack
void push(char c) {
    if (top < MAX - 1) stackArr[++top] = c;
}

// pop from stack
char pop() {
    if (top == -1) return '\0';
    return stackArr[top--];
}

// peek top element
char peek() {
    if (top == -1) return '\0';
    return stackArr[top];
}

// check precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// infix to postfix conversion
void infixToPostfix(const char* infix, char* postfix) {
    int j = 0;  // index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand, add to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter Infix expression: ";
    cin.getline(infix, MAX);
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

char st[100];
int top = -1;

void push(char x) {
    st[++top] = x;
}

char pop() {
    return st[top--];
}

char peek() {
    return st[top];
}

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main() {
    string infix, postfix = "";
    cin >> infix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix += pop();

            if (top != -1)
                pop();
        }
        else {
            while (top != -1 && peek() != '(' &&
                   priority(peek()) >= priority(c))
                postfix += pop();

            push(c);
        }
    }

    while (top != -1)
        postfix += pop();

    cout << "Postfix: " << postfix;

    return 0;
}
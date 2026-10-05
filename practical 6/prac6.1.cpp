#include <iostream>
#include <string>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int n;

public:
    Stack(int size) {
        n = size;
        top = -1;
    }

    void push(int tray) {
        if (top == n - 1) {
            cout << "Error: Stack is full\n";
            return;
        }

        arr[++top] = tray;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty\n";
            return;
        }

        top--;

        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Stack s(n);

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "place") {
            int tray;
            cin >> tray;
            s.push(tray);
        }
        else if (op == "take") {
            s.pop();
        }
    }

    return 0;
}
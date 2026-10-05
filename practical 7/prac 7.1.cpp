#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear, n;

public:
    Queue(int size) {
        n = size;
        front = -1;
        rear = -1;
    }

    void join(int x) {
        if (rear == n - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    void serve() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        front++;

        if (front > rear)
            front = rear = -1;
    }

    void displayFront() {
        if (front == -1)
            cout << "Queue Empty\n";
        else
            cout << "Front: " << arr[front] << endl;
    }
};

int main() {
    Queue q(5);

    q.join(101);
    q.displayFront();

    q.join(102);
    q.displayFront();

    q.serve();
    q.displayFront();

    q.join(103);
    q.displayFront();

    q.serve();
    q.displayFront();

    return 0;
}
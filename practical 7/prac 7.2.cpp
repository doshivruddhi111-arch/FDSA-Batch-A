#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void arrive(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void attend() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void displayFront() {
        if (front == NULL)
            cout << "Queue Empty\n";
        else
            cout << "Front: " << front->data << endl;
    }
};

int main() {
    Queue q;

    q.arrive(101);
    q.displayFront();

    q.arrive(102);
    q.displayFront();

    q.attend();
    q.displayFront();

    q.arrive(103);
    q.displayFront();

    q.attend();
    q.displayFront();

    return 0;
}
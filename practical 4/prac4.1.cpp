#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;

    Node(int x) {
        token = x;
        next = NULL;
    }
};

void display(Node* head) {
    while (head != NULL) {
        cout << head->token << " ";
        head = head->next;
    }
    cout << endl;
}

void insertFront(Node*& head, int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void insertEnd(Node*& head, int x) {
    Node* n = new Node(x);

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void insertPos(Node*& head, int x, int pos) {
    if (pos <= 1) {
        insertFront(head, x);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* n = new Node(x);
    n->next = temp->next;
    temp->next = n;
}

int main() {
    Node* head = NULL;
    int choice, token, pos;

    do {
        cout << "\n1. Critical Patient (Front)";
        cout << "\n2. Routine Patient (End)";
        cout << "\n3. Priority Patient (Position)";
        cout << "\n4. Display";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token: ";
                cin >> token;
                insertFront(head, token);
                display(head);
                break;

            case 2:
                cout << "Enter token: ";
                cin >> token;
                insertEnd(head, token);
                display(head);
                break;

            case 3:
                cout << "Enter token and position: ";
                cin >> token >> pos;
                insertPos(head, token, pos);
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 0);

    return 0;
}
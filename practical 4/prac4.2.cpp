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

void deleteToken(Node*& head, int x) {
    if (head == NULL) return;

    // Delete first node
    if (head->token == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->token != x)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Token not found!" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void reversePrint(Node* head) {
    if (head == NULL)
        return;

    reversePrint(head->next);
    cout << head->token << " ";
}

int main() {
    Node* head = NULL;
    int choice, token;

    do {
        cout << "\n1. Add Patient at Front";
        cout << "\n2. Add Patient at End";
        cout << "\n3. Delete Patient by Token";
        cout << "\n4. Display Forward";
        cout << "\n5. Display Reverse";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter token: ";
            cin >> token;

            Node* n = new Node(token);
            n->next = head;
            head = n;
            break;
        }

        case 2: {
            cout << "Enter token: ";
            cin >> token;

            Node* n = new Node(token);

            if (head == NULL)
                head = n;
            else {
                Node* temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = n;
            }
            break;
        }

        case 3:
            cout << "Enter token to delete: ";
            cin >> token;
            deleteToken(head, token);
            break;

        case 4:
            cout << "Queue: ";
            display(head);
            break;

        case 5:
            cout << "Reverse Queue: ";
            reversePrint(head);
            cout << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
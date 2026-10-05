#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;
}

void back() {
    if (top != NULL && top->next != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void display() {
    if (top != NULL)
        cout << "Current Page: " << top->page << endl;
    else
        cout << "No Page" << endl;
}

int main() {
    int n;
    cin >> n;

    string operation, page;

    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "VISIT") {
            cin >> page;
            visit(page);
        }
        else if (operation == "BACK") {
            back();
        }

        display();
    }

    return 0;
}
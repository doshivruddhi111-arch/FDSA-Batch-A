#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node *prev, *next;

    Node(string s) {
        song = s;
        prev = next = NULL;
    }
};

class Playlist {
    Node *head, *tail;

public:
    Playlist() {
        head = tail = NULL;
    }

    void addFirst(string s) {
        Node* n = new Node(s);

        if (!head)
            head = tail = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addLast(string s) {
        Node* n = new Node(s);

        if (!head)
            head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void insertAfter(string key, string s) {
        Node* t = head;

        while (t && t->song != key)
            t = t->next;

        if (!t) {
            cout << "Song not found\n";
            return;
        }

        Node* n = new Node(s);
        n->next = t->next;
        n->prev = t;

        if (t->next)
            t->next->prev = n;
        else
            tail = n;

        t->next = n;
    }

    void removeFirst() {
        if (!head) return;

        Node* t = head;
        head = head->next;

        if (head)
            head->prev = NULL;
        else
            tail = NULL;

        delete t;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->song << " ";
            t = t->next;
        }
        cout << endl;
    }

    int count() {
        int c = 0;
        for (Node* t = head; t; t = t->next)
            c++;
        return c;
    }
};

int main() {
    Playlist p;

    p.addFirst("A");
    p.addLast("B");
    p.insertAfter("A", "C");

    p.display();
    cout << "Count: " << p.count() << endl;

    p.removeFirst();
    p.display();
}
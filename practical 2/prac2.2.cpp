#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of records: ";
    cin >> n;

    int books[100];

    cout << "Enter book IDs: ";

    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (books[i] > books[j]) {
                int temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    cout << "Books borrowed more than once: ";

    for (int i = 0; i < n - 1; i++) {

        if (books[i] == books[i + 1]) {
            cout << books[i] << " ";
        }
    }

    return 0;
}
